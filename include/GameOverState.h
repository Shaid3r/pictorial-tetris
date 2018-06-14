#pragma once

#include <State.h>

/**
 * @brief Reprezentuje stan końca gry.
 */
class GameOverState : public State {
public:
    /**
     * @brief Konstruuje GameOverState.
     */
    GameOverState();
    /**
     * @brief Przetwarza wejściowe zdarzenia pochodzące od użytkownika.
     *
     * @param event Zdarzenie pochodzące od użytkownika.
     */
    void handleInput(sf::Event &event) override;
    /**
     * @brief Aktualizuje aktualny stan.
     *
     * @param dt Czas renderowania i przetwarzania poprzedniej klatki gry.
     */
    void update(float dt) override;

    /**
     * @brief Renderuje stan gry.
     */
    void render() override;

private:
    int finalScore;
};
