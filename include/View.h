#pragma once

class View {
public:
    View();

    sf::RenderWindow &getWindow();
    sf::Font &getFont();

    unsigned int getHeight() const;
    unsigned int getWidth() const;

private:
    sf::VideoMode desktop;
    sf::Font font;
    std::unique_ptr<sf::RenderWindow> window;
};



