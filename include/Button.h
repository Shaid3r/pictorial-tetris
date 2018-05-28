#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

class Button : public sf::RectangleShape {
public:
    Button(float width, float height, const sf::String &text = "",
           unsigned int size = TEXT_SIZE);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void select();
    void unselect();

    void setText(sf::Text &text);
    void setString(const sf::String &string);
    void setPosition(float x, float y);

private:
    bool setTextPosition();

    static const sf::Color COLOR_SELECTED;
    static const sf::Color COLOR_DEFAULT;
    static const sf::Color COLOR_TXT_SELECTED;
    static const sf::Color COLOR_TXT_DEFAULT;
    static const unsigned int TEXT_SIZE;

    sf::Text text;
    bool selected{false};
};



