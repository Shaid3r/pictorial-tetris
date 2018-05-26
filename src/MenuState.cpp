#include <Game.h>
#include "MenuState.h"

MenuState::MenuState() {
    View &view = Game::getView();
    const int WIDTH = view.getWidth();
    const int HEIGHT = view.getHeight();

    const int BTN_WIDTH = 200;
    const int BTN_HEIGHT = 40;
    const int BTN_TOP_MARGIN = HEIGHT * 0.02f;
    const int BUTTONS_COUNT = 4;

    int startHPos =
            (HEIGHT - BUTTONS_COUNT * (BTN_HEIGHT + BTN_TOP_MARGIN)) / 2;
    int startWPos = (WIDTH - BTN_WIDTH) / 2;

    for (int i = 0; i < BUTTONS_COUNT; ++i) {
        buttons.emplace_back(BTN_WIDTH, BTN_HEIGHT);
        buttons[i].setPosition(startWPos, startHPos);

        startHPos += BTN_HEIGHT + BTN_TOP_MARGIN;
    }

    buttons[START].setString("START");
    buttons[HELP].setString("HELP");
    buttons[TOP10].setString("TOP10");
    buttons[EXIT].setString("EXIT");

    buttons[START].select();
}

void MenuState::handleInput(sf::Event &event) {
    if (event.type == sf::Event::EventType::KeyPressed) {
        switch (event.key.code) {
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

void MenuState::update(float dt) {}

void MenuState::render() {
    if (updated) {
        View &view = Game::getView();
        sf::RenderTarget &target = view.getWindow();
        target.clear(COLOR_BACKGROUND);

        sf::Text title("TETRIS", view.getFont(), 80);
        title.setPosition(
                (view.getWidth() - title.getLocalBounds().width) / 2,
                view.getHeight() * 0.1);
        target.draw(title);

        for (auto &button : buttons)
            target.draw(button);

        updated = false;
    }
}

void MenuState::selectPrevious() {
    buttons[selected].unselect();
    selected = (selected - 1) % buttons.size();
    buttons[selected].select();
    updated = true;
}

void MenuState::selectNext() {
    buttons[selected].unselect();
    selected = (selected + 1) % buttons.size();
    buttons[selected].select();
    updated = true;
}

void MenuState::enter() {
    switch (selected) {
        case MenuState::START:
//            gsm.set(std::make_unique<StartState>(gsm));
            break;
        case MenuState::HELP:
//            gsm.set(std::make_unique<HelpState>(gsm));
            break;
        case MenuState::TOP10:
//            gsm.set(std::make_unique<RankingState>(gsm));
            break;
        case MenuState::EXIT:
            Game::getView().getWindow().close();
            break;
        default:
            break;
    }
}

