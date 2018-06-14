#pragma once

#include <SFML/System/String.hpp>
#include <Button.h>

/**
 * @brief Reprezentuje przycisk z wyborem opcji.
 */
class MultiOptionField : public Button {
public:
    /**
     * @brief Konstruuje MultiOptionField o podanych rozmiarach i pozostałych parametrach.
     *
     * @param width Szerokość w pikselach.
     * @param height Wysokość w pikselach.
     * @text Tekst widoczny na przycisku. Domyślnie pusty tekst.
     * @size Rozmiar czcionki tekstu. Domyślnie 0.5.
     * @percent Procent zajmowanej szerokości. Domyślnie 0.5 (50%).
     */
    MultiOptionField(float width, float height, const sf::String &text="",
                     unsigned int size=30, float percent = 0.5);

    /**
     * @brief Renderuje przycisk z wyborem opcji.
     *
     * @param target RenderTarged, do ktorego przycisk z wyborem opcji ma być renderowany.
     * @param states Stany renderowania.
     */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    /**
     * @brief Dodaje nową opcję do wyboru.
     * @details Jeżeli żadna opcjia nie istniała, dodaje ją i ustawia ją jako aktualną
     * opcję.
     *
     * @param option Opcja do dodania.
     */
    void addOption(const sf::String &option);

    /**
     * @brief Ustawia aktualną opcję.
     *
     * @param int Indeks aktualnej opcji.
     */
    void setCurrent(unsigned int idx);

    /**
     * @brief Ustawia pozycję przycisku z wyborem opcji.
     *
     * @param x Współrzędna na osi OX w pikselach.
     * @param y Współrzędna na osi OY w pikselach.
     */
    void setPosition(float x, float y);

    /**
     * @brief Ustawia tekst opcji o podanym indeksie.
     *
     * @param int Indeks opcji.
     * @param s Tekst do ustawienia.
     */
    void setOptionString(unsigned int idx, const sf::String &s);

    /**
     * @brief Ustawia następną możliwą opcję.
     *
     * @return Indeks nowej opcji.
     */
    unsigned int selectNext();

    /**
     * @brief Ustawia poprzednią możliwą opcję.
     *
     * @return Indeks nowej opcji.
     */
    unsigned int selectPrevious();

private:
    bool setTextOptionPosition();
    sf::Text text_option;
    std::vector<sf::String> options;
    int selected_option = 0;
    float percent;
};
