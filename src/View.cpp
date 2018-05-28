#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "View.h"
#include "Game.h"

View::View() {
    desktop = sf::VideoMode().getFullscreenModes()[0];
    window = std::make_unique<sf::RenderWindow>(desktop, Game::TITLE,
                                                sf::Style::Fullscreen);
    window->setFramerateLimit(60);
    window->setMouseCursorVisible(false);

    if (!font.loadFromFile("data/NotoSerif-Regular.ttf"))
        throw std::runtime_error("cannot load font");

    for (unsigned int i = 0; i < IMAGES_COUNT; ++i)
        enableImg(i);
}

sf::RenderWindow &View::getWindow() {
    return *window;
}

sf::Font &View::getFont() {
    return font;
}

void View::enableImg(unsigned int idx) {
    img[idx].loadFromFile("data/img" + std::to_string(idx) + ".jpg");
}

void View::loadImg2Texture(unsigned int idx) {
    if (!texture.loadFromImage(img[idx]))
        throw std::runtime_error("Cannot load image");
}

void View::setGrayscale(unsigned int idx) {
    unsigned int width = img[idx].getSize().x;
    unsigned int height = img[idx].getSize().y;

    for (unsigned int y = 0; y < height; ++y)
        for (unsigned int x = 0; x < width; ++x)
            img[idx].setPixel(x, y, toGrayscale(img[idx].getPixel(x, y)));
}

sf::Sprite View::resize(float width, float height) {
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

unsigned int View::getHeight() const {
    return desktop.height;
}

unsigned int View::getWidth() const {
    return desktop.width;
}

sf::Color View::toGrayscale(const sf::Color &color) {
    auto avg = static_cast<sf::Uint8>(
            color.r * 0.12f + color.g * 0.72f + color.b * 0.07f);
    return {avg, avg, avg};
}
