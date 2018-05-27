#pragma once

class View {
public:
    View();

    sf::RenderWindow &getWindow();
    sf::Font &getFont();

    unsigned int getHeight() const;
    unsigned int getWidth() const;

    sf::Image img;
    sf::Texture texture;
private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::Font font;
    sf::VideoMode desktop;
};



