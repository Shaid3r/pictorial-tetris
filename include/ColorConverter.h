#pragma once

#include <cstdint>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>

class ColorConverter {
public:
/*
 * Luminosity method of changing rgb to grayscale
 */
    static sf::Color toGrayscale(const sf::Color &color);

    static void imgToGrayscale(sf::Image img);

    static sf::Sprite resize(sf::Texture &texture, float width, float height);
};



