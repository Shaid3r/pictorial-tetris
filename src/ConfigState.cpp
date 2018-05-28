#include <Game.h>
#include "ConfigState.h"

ConfigState::ConfigState() {
    View &view = Game::getView();
    const int WIDTH = view.getWidth();
    const int HEIGHT = view.getHeight();

    const int FLD_WIDTH = WIDTH * 0.5;
    const int FLD_HEIGHT = 45;
    const int FLD_TOP_MARGIN = HEIGHT * 0.05f;
    const int FIELDS_COUNT = 3;

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

    fields[VBLOCKS].setString("Number of vertical blocks");
    fields[VBLOCKS].addOption("4");

    fields[HBLOCKS].setString("Number of horizontal blocks");
    fields[HBLOCKS].addOption("4");

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
    target.clear(COLOR_BACKGROUND);

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
    selected = (selected - 1) % fields.size();
    fields[selected].select();
    updated = true;
}

void ConfigState::selectLeft() {
    Config &config = Game::getConfig();
    if (selected == VBLOCKS) {
        config.setVBlocks(config.getVBlocks() - 1);
        fields[selected].setOptionString(0, std::to_string(config.getVBlocks()));
    } else if (selected == HBLOCKS) {
        config.setHBlocks(config.getHBlocks() - 1);
        fields[selected].setOptionString(0, std::to_string(config.getHBlocks()));
    } else
        config.level = static_cast<Config::LEVEL>(fields[selected].selectPrevious());
    updated = true;
}

void ConfigState::selectRight() {
    Config &config = Game::getConfig();
    if (selected == VBLOCKS) {
        config.setVBlocks(config.getVBlocks() + 1);
        fields[selected].setOptionString(0, std::to_string(config.getVBlocks()));
    } else if (selected == HBLOCKS) {
        config.setHBlocks(config.getHBlocks() + 1);
        fields[selected].setOptionString(0, std::to_string(config.getHBlocks()));
    } else
        config.level = static_cast<Config::LEVEL>(fields[selected].selectNext());
    updated = true;
}

void ConfigState::enter() {
//    if (selected_option == 3)
//    Game::getGSM().push(std::make_unique<PlayState>());
}
