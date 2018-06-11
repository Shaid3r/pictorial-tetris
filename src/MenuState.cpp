#include <Game.h>
#include <StartState.h>
#include <HelpState.h>
#include <iostream>
#include <MenuState.h>

MenuState::MenuState() {
    View &view = Game::getView();
    const int WIDTH = view.getWidth();
    const int HEIGHT = view.getHeight();

    const int BTN_WIDTH = 200;
    const int BTN_HEIGHT = 40;
    const int BTN_TOP_MARGIN = HEIGHT * 0.02f;
    const int BUTTONS_COUNT = 3;

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

void MenuState::update(float) {}

void MenuState::render() {
    View &view = Game::getView();
    sf::RenderTarget &target = view.getWindow();
    target.clear(Game::getView().getBackgroundColor());

    sf::Text title("TETRIS", view.getFont(), 80);
    title.setPosition(
            (view.getWidth() - title.getLocalBounds().width) / 2,
            view.getHeight() * 0.1);
    target.draw(title);

    for (auto &button : buttons)
        target.draw(button);

}

void MenuState::selectNext() {
    buttons[selected].unselect();
    selected = (selected + 1) % buttons.size();
    buttons[selected].select();
    updated = true;
}

void MenuState::selectPrevious() {
    buttons[selected].unselect();
    if (--selected < 0) selected += buttons.size();
    buttons[selected].select();
    updated = true;
}

void MenuState::enter() {
    switch (selected) {
        case MenuState::START:
            Game::getGSM().set(std::make_unique<StartState>());
            break;
        case MenuState::HELP:
            Game::getGSM().push(std::make_unique<HelpState>());
            break;
        case MenuState::EXIT:
            Game::getView().getWindow().close();
            break;
        default:
            break;
    }
}

