#pragma once

/**
 * @brief Reprezentuje widok.
 */
class View {
public:
    /**
     * @brief Konstruuje View, tworząc okno gry, ustawiając rozdzielczość i inne niezbędne
     * parametry.
     */
    View();

    /**
     * @brief Zwraca okno gry.
     * @return Okno gry.
     */
    sf::RenderWindow &getWindow();

    /**
     * @brief Zwraca czcionkę wykorzystywaną w grze.
     * @return Czcionka.
     */
    sf::Font &getFont();

    /**
     * @brief Zwraca teksturę zawierającą obrazek gry.
     * @return Tekstura zawierająca obrazek gry.
     */
    sf::Texture& getTexture();

    /**
     * @brief Zwraca kolor tła.
     * @return Kolor tła.
     */
    const sf::Color& getBackgroundColor() const;

    /**
     * @brief Ładuje obrazek do tablicy obrazków do podanego indeksu.
     * @details Tablica przyjmuję ściśle określoną maksymalną liczbę obrazków do pamięci.
     * Dodatkowo każdy obrazek musi znajdować się w katalogu "data" i nazywać się
     * "imgX.jpg", gdzie X jest także numerem indeksu w tablicy, gdzie zostanie zapisany.
     *
     * @param int Indeks tablicy i końcówka nazwy pliku z obrazkiem.
     */
    void enableImg(unsigned int idx);

    /**
     * @brief Ustawia aktualny obrazek gry na podstawie indeksu tablicy z obrazkami.
     *
     * @param int Indeks tablicy.
     */
    void loadImg2Texture(unsigned int idx);

    /**
     * @brief Przeskalowuje obrazek do odpowiednich wymiarów.
     *
     * @param texture Tekstura do przeskalowania.
     * @param width Oczekiwana szerokość w pikselach.
     * @param height Oczekiwana wysokość w pikselach.
     * @return Obiekt Sprite zawierający przeskalowany obrazek.
     */
    sf::Sprite resize(sf::Texture& texture, float width, float height);

    /**
     * @brief Zwraca wysokość okna gry.
     *
     * @return Wysokość okna gry w pikselach.
     */
    unsigned int getHeight() const;

    /**
     * @brief Zwraca szerokość okna gry.
     *
     * @return Szerokość okna gry w pikselach.
     */
    unsigned int getWidth() const;

    /**
     * Przechowuje ilość przechowywanych obrazków w tablicy.
     */
    static const unsigned int IMAGES_COUNT = 4;

    /**
     * Przechowuje czas gry.
     */
    float time{0};

private:
    const sf::Color COLOR_BACKGROUND{12, 24, 24};

    std::unique_ptr<sf::RenderWindow> window;
    sf::Texture texture;
    sf::Image img[IMAGES_COUNT];

    sf::Font font;
    sf::VideoMode desktop;
};
