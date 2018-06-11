#pragma once

class View {
public:
    View();

    sf::RenderWindow &getWindow();
    sf::Font &getFont();
    sf::Texture& getTexture();
    const sf::Color& getBackgroundColor() const;

    void enableImg(unsigned int idx);
    void loadImg2Texture(unsigned int idx);
    sf::Sprite resize(sf::Texture& texture, float width, float height);

    unsigned int getHeight() const;
    unsigned int getWidth() const;

    static const unsigned int IMAGES_COUNT = 4;

    float time{0};

private:
    const sf::Color COLOR_BACKGROUND{12, 24, 24};

    std::unique_ptr<sf::RenderWindow> window;
    sf::Texture texture;
    sf::Image img[IMAGES_COUNT];

    sf::Font font;
    sf::VideoMode desktop;
};



