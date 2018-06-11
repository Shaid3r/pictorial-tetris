#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>
#include <Game.h>
#include <Button.h>

const sf::Color Button::COLOR_SELECTED{255, 0, 0};
const sf::Color Button::COLOR_DEFAULT{0, 255, 0};
const sf::Color Button::COLOR_TXT_SELECTED{0, 0, 0};
const sf::Color Button::COLOR_TXT_DEFAULT{255, 255, 255};
const unsigned int Button::TEXT_SIZE = 25;

Button::Button(float width, float height, const sf::String &text,
               unsigned int size)
        : sf::RectangleShape(sf::Vector2f(width, height)),
          text(text, Game::getView().getFont(), size) {
    this->setFillColor(COLOR_DEFAULT);
    this->text.setFillColor(COLOR_TXT_DEFAULT);
    setString(text);
}

void Button::select() {
    selected = true;
    this->setFillColor(COLOR_SELECTED);
    text.setFillColor(COLOR_TXT_SELECTED);
}

void Button::unselect() {
    selected = false;
    setFillColor(COLOR_DEFAULT);
    text.setFillColor(COLOR_TXT_DEFAULT);
}

void Button::setText(sf::Text &text) {
    this->text = text;
}

void Button::setString(const sf::String &string) {
    text.setString(string);
    for (unsigned int i = 0; !setTextPosition() && i < text.getCharacterSize()/2; ++i)
        text.setCharacterSize(text.getCharacterSize() - 1);
}

bool Button::setTextPosition() {
    float width = (getLocalBounds().width - text.getLocalBounds().width) / 2.f;
    if (width < 0) return false;

    float height =
            (getLocalBounds().height - text.getLocalBounds().height) / 2.f
            - text.getCharacterSize() * 0.25f;

    text.setPosition(getPosition() + sf::Vector2f(width, height));
    return true;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(static_cast<sf::RectangleShape>(*this), states);
    target.draw(text, states);
}

void Button::setPosition(float x, float y) {
    Transformable::setPosition(x, y);
    setTextPosition();
}
