#pragma once

#include <State.h>
#include <Button.h>
#include <MultiOptionField.h>

/**
 * @brief Reprezentuje stan bycia w konfiguracji gry.
 */
class ConfigState : public State {
public:
    /**
     * @brief Konstruuje ConfigState.
     */
    ConfigState();

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
    enum FIELDS {
        LEVEL,
        BLOCKS,
        START
    };

    void selectNext();
    void selectPrevious();
    void selectLeft();
    void selectRight();
    void enter();

    std::vector<MultiOptionField> fields;
    int selected{0};
};
