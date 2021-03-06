#include <Game.h>
#include <PlayState.h>
#include <ConfigState.h>

ConfigState::ConfigState() {
    View &view = Game::getView();
    const int WIDTH = view.getWidth();
    const int HEIGHT = view.getHeight();

    const int FLD_WIDTH = WIDTH * 0.5;
    const int FLD_HEIGHT = 45;
    const int FLD_TOP_MARGIN = HEIGHT * 0.05f;
    const int FIELDS_COUNT = 2;

    int startHPos =
            (HEIGHT - FIELDS_COUNT * (FLD_HEIGHT + FLD_TOP_MARGIN)) / 2;
    int startWPos = (WIDTH - FLD_WIDTH) / 2;

    for (int i = 0; i < FIELDS_COUNT; ++i) {
        fields.emplace_back(FLD_WIDTH, FLD_HEIGHT);
        fields[i].setPosition(startWPos, startHPos);

        startHPos += FLD_HEIGHT + FLD_TOP_MARGIN;
    }
    fields.emplace_back(FLD_WIDTH, 55, "", 30, 1);
    fields[START].setPosition(startWPos, startHPos);

    fields[LEVEL].setString("Level");
    fields[LEVEL].addOption("EASY");
    fields[LEVEL].addOption("NORMAL");
    fields[LEVEL].addOption("HARD");
    fields[LEVEL].setCurrent(1);

    fields[BLOCKS].setString("Number of blocks");
    int blocksCount = Game::getConfig().getBlocks();
    fields[BLOCKS].addOption(std::to_string(blocksCount*blocksCount));

    fields[START].setString("Start");

    fields[LEVEL].select();
}

void ConfigState::handleInput(sf::Event &event) {
    if (event.type == sf::Event::EventType::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Escape:
                Game::getGSM().pop();
                break;
            case sf::Keyboard::Left:
                selectLeft();
                break;
            case sf::Keyboard::Right:
                selectRight();
                break;
            case sf::Keyboard::Up:
                selectPrevious();
                break;
            case sf::Keyboard::Down:
                selectNext();
                break;
            case sf::Keyboard::Enter:
            case sf::Keyboard::Space:
                enter();
                break;
            default:
                break;
        }
    }
}

void ConfigState::update(float) {}

void ConfigState::render() {
    View &view = Game::getView();
    sf::RenderTarget &target = view.getWindow();
    target.clear(Game::getView().getBackgroundColor());

    sf::Text title("Settings", view.getFont(), 40);
    title.setPosition(
            (view.getWidth() - title.getLocalBounds().width) / 2.f,
            view.getHeight() * 0.07f);
    target.draw(title);

    for (auto &field : fields)
        target.draw(field);
}

void ConfigState::selectNext() {
    fields[selected].unselect();
    selected = (selected + 1) % fields.size();
    fields[selected].select();
    updated = true;
}

void ConfigState::selectPrevious() {
    fields[selected].unselect();
    if (--selected < 0) selected += fields.size();
    fields[selected].select();
    updated = true;
}

void ConfigState::selectLeft() {
    Config &config = Game::getConfig();
    if (selected == BLOCKS) {
        config.setBlocks(config.getBlocks() - 1);
        fields[selected].setOptionString(0, std::to_string(
                config.getBlocks() * config.getBlocks()));
    } else
        config.level = static_cast<Config::LEVEL>(fields[selected].selectPrevious());
    updated = true;
}

void ConfigState::selectRight() {
    Config &config = Game::getConfig();
    if (selected == BLOCKS) {
        config.setBlocks(config.getBlocks() + 1);
        fields[selected].setOptionString(0, std::to_string(
                config.getBlocks() * config.getBlocks()));
    } else
        config.level = static_cast<Config::LEVEL>(fields[selected].selectNext());
    updated = true;
}

void ConfigState::enter() {
    if (selected == START)
        Game::getGSM().push(std::make_unique<PlayState>());
}
