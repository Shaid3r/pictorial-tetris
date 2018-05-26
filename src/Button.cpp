#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>
#include <Game.h>
#include "Button.h"

Button::Button(float width, float height, const sf::String &text)
        : sf::RectangleShape(sf::Vector2f(width, height)),
          text(text, Game::getView().getFont(), TEXT_SIZE) {
    this->setFillColor(COLOR_DEFAULT);
    this->text.setFillColor(COLOR_TXT_DEFAULT);
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

void Button::setString(sf::String &&string) {
    text.setString(string);
    float width = (getLocalBounds().width - text.getLocalBounds().width) / 2.f;
    float height =
            (getLocalBounds().height - text.getLocalBounds().height) / 2.f
            - TEXT_SIZE * 0.25f;

    text.setPosition(getPosition() + sf::Vector2f(width, height));
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(static_cast<sf::RectangleShape>(*this), states);
    target.draw(text, states);
}
