#include <MenuState.h>
#include "Game.h"

const sf::VideoMode Game::desktop = sf::VideoMode().getFullscreenModes()[0];
const std::string Game::TITLE = "Tetris";

Game::Game() {
    window = std::make_unique<sf::RenderWindow>(desktop, TITLE, sf::Style::Fullscreen);
    window->setFramerateLimit(60);
}

void Game::run() {
    gsm.set(std::make_unique<MenuState>(gsm));
    sf::Clock clock;
    clock.restart();
    while (window->isOpen()) {
        handleInput();
        gsm.update(clock.restart().asSeconds());
        gsm.render(*window);
        window->display();
    }
}

void Game::handleInput() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        gsm.handleInput(event);
    }
}
