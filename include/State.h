#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Reprezentuje abstrakcyjny stan.
 */
class State {
public:
    /**
     * @brief Konstruuje obiekt abstrakcyjnego stanu. Konstruktor pusty.
     */
    State() = default;

    /**
     * @brief Wirtualny pusty destruktor.
     */
    virtual ~State() {}

    /**
     * @brief Przetwarza wejściowe zdarzenia pochodzące od użytkownika. Czysto
     * abstrakcyjna metoda.
     *
     * @param event Zdarzenie pochodzące od użytkownika.
     */
    virtual void handleInput(sf::Event &event) = 0;

    /**
     * @brief Aktualizuje aktualny stan. Czysto abstrakcyjna metoda.
     *
     * @param dt Czas renderowania i przetwarzania poprzedniej klatki gry.
     */
    virtual void update(float dt) = 0;

    /**
     * @brief Renderuje stan gry. Czysto abstrakcyjna metoda.
     */
    virtual void render() = 0;

protected:
    /**
     * Przechowuje informację o tym, czy stan został zaktualizowany.
     */
    bool updated{true};
};
