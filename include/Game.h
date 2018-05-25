#pragma once

#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameStateManager.h"

class Game {
public:
    static Game& getInstance() {
        static Game game;
        return game;
    }

    void run();

private:
    Game();
    Game(const Game& game) = delete;
    void operator=(const Game& game) = delete;

    void handleInput();

    static const sf::VideoMode desktop;
    static const std::string TITLE;
    GameStateManager gsm;
    std::unique_ptr<sf::RenderWindow> window;
};