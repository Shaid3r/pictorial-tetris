#pragma once

#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <GameStateManager.h>
#include <Config.h>
#include <View.h>

/**
 * @brief Reprezentuje gre.
 * @details Singleton -- jednocześnie może występować tylko jedna instancja gry.
 */
class Game {
public:
    /**
     * @brief Zwraca instancję obiektu Game.
     *
     * @return Instancja obiektu Game.
     */
    static Game &getInstance();

    /**
     * @brief Zwraca referencję do widoku View.
     *
     * @return Referencja do View.
     */
    static View &getView();

    /**
     * @brief Zwraca referencję do konfiguracji Config.
     *
     * @return Referencja do Config.
     */
    static Config &getConfig();

    /**
     * @brief Zwraca menadżer stanów GameStateManager.
     *
     * @return Referencja do GameStateManager.
     */
    static GameStateManager &getGSM();

    /**
     * @brief Uruchamia grę.
     */
    void run();

    /**
     * @brief Przechowuje tytuł gry.
     */
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
