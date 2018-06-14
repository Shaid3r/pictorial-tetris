#pragma once

#include "State.h"
#include "Button.h"

class StartState : public State {
public:
    StartState();

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
    void selectNext();
    void selectPrevious();
    void enter();

    static const unsigned int BTN_WIDTH = 200;
    static const unsigned int BTN_HEIGHT = 45;
    static const std::string BTN_TXT;

    Button selectBtn;
    unsigned int selected{0};
};



