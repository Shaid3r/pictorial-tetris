#pragma once

#include <State.h>
#include <Button.h>

/**
 * @brief Reprezentuje stan bycia w menu głównym.
 */
class MenuState : public State {
public:
    /**
     * @brief Konstruuje MainMenu.
     */
    MenuState();

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

    enum BUTTONS {
        START,
        HELP,
        EXIT
    };

    std::vector<Button> buttons;
    int selected{0};
};
