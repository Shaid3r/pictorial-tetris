#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Button : public sf::RectangleShape {
public:
    Button(float width, float height, const sf::String &text = "");

    void select();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void unselect();

    void setText(sf::Text &text);

    void setString(sf::String &&string);

private:
    const sf::Color COLOR_SELECTED{255, 0, 0};
    const sf::Color COLOR_DEFAULT{0, 255, 0};
    const sf::Color COLOR_TXT_SELECTED{0, 0, 0};
    const sf::Color COLOR_TXT_DEFAULT{255, 255, 255};
    const unsigned int TEXT_SIZE = 25;

    sf::Text text;
    bool selected{false};
};



