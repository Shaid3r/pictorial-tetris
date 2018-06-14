#pragma once

#include <memory>
#include <stack>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <State.h>

/**
 * @brief Reprezentuje kontroler stanów aplikacji.
 */
class GameStateManager {
public:
    /**
     * @brief Przetwarza zdarzenie pochodzące od gracza przez aktualny stan aplikacji.
     *
     * @param event Zdarzenie pochodzące od gracza.
     */
    void handleInput(sf::Event &event);

    /**
     * @brief Aktualizuje aktualny stan aplikacji.
     *
     * @param dt Czas renderowania i przetwarzania poprzedniej klatki gry.
     */
    void update(float dt);

    /**
     * @brief Renderuje aktualn stan gry.
     */
    void render();

    /**
     * @brief Ustawia aktualny stan aplikacji.
     *
     * @param state Nowy stan do ustawienia.
     */
    void push(std::unique_ptr<State> state);

    /**
     * @brief Zamyka ostatni stan aplikacji.
     */
    void pop();

    /**
     * @brief Zamyka poprzednie stany aplikacji i ustawia nowy.
     *
     * @param state Nowy stan do ustawienia.
     */
    void set(std::unique_ptr<State> state);

private:
	std::stack<std::unique_ptr<State>> states;
};
