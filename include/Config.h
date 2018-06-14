#pragma once

/**
 * @brief Reprezentuje konfigurację i ustawienia gry.
 */
class Config {
public:
    /**
     * @brief Ustawia ilość klocków na bok.
     *
     * @param x Ilość klocków na bok.
     */
    void setBlocks(unsigned int x);

    /**
     * @brief Zwraca ilość klocków na bok.
     *
     * @return Ilość klocków na bok.
     */
    unsigned int getBlocks() const;

    /**
     * Reprezentuje poziomy trudności gry.
     */
    enum LEVEL {
        EASY,
        NORMAL,
        HARD
    };

    /**
     * @brief Przechowuje minimalną możliwą ilość klocków na bok.
     */
    static const int MIN_BLOCKS = 2;

    /**
     * @brief Przechowuje maksymalną możliwą ilość klocków na bok.
     */
    static const int MAX_BLOCKS = 10;

    /**
     * @brief Zwraca szybkość opadania klocków.
     *
     * @return Szybkość opadania klocków.
     */
    double getVelocity() const;

    /**
     * @brief Przechowuje aktualny poziom trudności gry.
     */
    LEVEL level = NORMAL;
private:
    const float velocity = 0.5;
    unsigned int blocks = 4;
};



