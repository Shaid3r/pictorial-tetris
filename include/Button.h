#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

/**
 * @brief Reprezentuje przycisk wykorzystywany w menu gry.
 */
class Button : public sf::RectangleShape {
public:
    /**
     * @brief Konstruuje Button o podanych wymiarach i zawierający określony tekst.
     *
     * @param width Szerokość przycisku w pikselach.
     * @param height Wysokość przycisku w pikselach.
     * @param text Tekst wyświetlany na przycisku.
     * @param size Rozmiar tekstu.
     */
    Button(float width, float height, const sf::String &text = "",
           unsigned int size = TEXT_SIZE);

    /**
     * @brief Renderuje przycisk.
     *
     * @param target RenderTarget, do którego przycisk ma być renderowany.
     * @param states Stany renderowania.
     */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    /**
     * @brief Ustawia przycisk jako zaznaczony w danym momencie.
     * @details Zaznaczony przycisk ma inny kolor tła jak i tła tekstu.
     */
    void select();

    /**
     * @brief Ustawia przycisk jako nie zaznaczony w danym momencie.
     * @details Odznaczony przycisk ma domyślny kolor tła jak i tła tekstu.
     */
    void unselect();

    /**
     * @brief Ustawia obiekt Text widoczny na przycisku.
     *
     * @param text Text do ustawienia.
     */
    void setText(sf::Text &text);

    /**
     * @brief Ustawia tekst w zawartym obiekcie klasy Text.
     * @details Rozmiar czcionki jest automatycznie dopasowywany do rozmiarów przycisku,
     * jeżeli tekst by wystawał poza przycisk.
     *
     * @param string Tekst do ustawienia.
     */
    void setString(const sf::String &string);

    /**
     * @brief Zmienia położenie przycisku na ekranie.
     *
     * @param x Współrzędna na osi OX, w pikselach.
     * @param y Współrzędna na osi OY, w pikselach.
     */
    void setPosition(float x, float y);

private:
    bool setTextPosition();

    static const sf::Color COLOR_SELECTED;
    static const sf::Color COLOR_DEFAULT;
    static const sf::Color COLOR_TXT_SELECTED;
    static const sf::Color COLOR_TXT_DEFAULT;
    static const unsigned int TEXT_SIZE;

    sf::Text text;
    bool selected{false};
};
