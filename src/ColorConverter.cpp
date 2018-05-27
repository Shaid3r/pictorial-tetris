
#include <Game.h>
#include "ColorConverter.h"

sf::Color ColorConverter::toGrayscale(const sf::Color &color) {
    return {static_cast<sf::Uint8>(0.21 * color.r),
            static_cast<sf::Uint8>(0.72 * color.g),
            static_cast<sf::Uint8>(0.07 * color.b)};
}

void ColorConverter::imgToGrayscale(sf::Image img) {
    unsigned int width = img.getSize().x;
    unsigned int height = img.getSize().y;

    for (unsigned int y = 0; y < height; ++y)
        for (unsigned int x = 0; x < width; ++x)
            img.setPixel(x, y, toGrayscale(img.getPixel(x, y)));
}

sf::Sprite
ColorConverter::resize(sf::Texture &texture, float width, float height) {
    float want = width / height;
    float have = static_cast<float>(texture.getSize().x) / texture.getSize().y;
    sf::Sprite sprite(texture);

    if (have > want) { // maximum height
        float scale = height / texture.getSize().y;

        float w = texture.getSize().y * want;
        sprite.setTextureRect(sf::IntRect((texture.getSize().x - w) / 2, 0, w,
                                          texture.getSize().y));

        sprite.setScale(scale, scale);
    } else { // maximum height
        float scale = width / texture.getSize().x;

        float h = texture.getSize().x * 1 / want;
        sprite.setTextureRect(sf::IntRect(0, (texture.getSize().y - h) / 2.f,
                                          texture.getSize().x, h));
        sprite.setScale(scale, scale);
    }

    return sprite;
}
