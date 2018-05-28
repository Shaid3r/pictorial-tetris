#pragma once

class View {
public:
    View();

    sf::RenderWindow &getWindow();
    sf::Font &getFont();

    void enableImg(unsigned int idx);
    void loadImg2Texture(unsigned int idx);
    void setGrayscale(unsigned int idx);
    sf::Sprite resize(float width, float height);

    unsigned int getHeight() const;
    unsigned int getWidth() const;

    static const unsigned int IMAGES_COUNT = 4;

private:
    sf::Color toGrayscale(const sf::Color &color);

    std::unique_ptr<sf::RenderWindow> window;
    sf::Texture texture;
    sf::Image img[IMAGES_COUNT];

    sf::Font font;
    sf::VideoMode desktop;
};



