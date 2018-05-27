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

    img.loadFromFile("data/img1.jpg");

}

sf::RenderWindow &View::getWindow() {
    return *window;
}

sf::Font &View::getFont() {
    return font;
}

unsigned int View::getHeight() const {
    return desktop.height;
}

unsigned int View::getWidth() const {
    return desktop.width;
}
