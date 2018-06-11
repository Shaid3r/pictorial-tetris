#pragma once

#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <GameStateManager.h>
#include <Config.h>
#include <View.h>

class Game {
public:
    static Game &getInstance();
    static View &getView();
    static Config &getConfig();
    static GameStateManager &getGSM();

    void run();

    static const std::string TITLE;

private:
    Game() {};
    Game(const Game &game) = delete;
    void operator=(const Game &game) = delete;

    void handleInput();

    View view;
    Config config;
    GameStateManager gsm;
};