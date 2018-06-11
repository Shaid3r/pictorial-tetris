#include <MenuState.h>
#include <Game.h>

const std::string Game::TITLE = "Tetris";

Game &Game::getInstance() {
    static Game game;
    return game;
}

View &Game::getView() {
    return Game::getInstance().view;
}

Config &Game::getConfig() {
    return Game::getInstance().config;
}

GameStateManager &Game::getGSM() {
    return Game::getInstance().gsm;
}

void Game::run() {
    srand((time(0)));
    gsm.set(std::make_unique<MenuState>());
    sf::Clock clock;
    clock.restart();
    while (view.getWindow().isOpen()) {
        handleInput();
        gsm.update(clock.restart().asSeconds());
        gsm.render();
        view.getWindow().display();
    }
}

void Game::handleInput() {
    sf::Event event;
    while (view.getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            view.getWindow().close();
        gsm.handleInput(event);
    }
}
