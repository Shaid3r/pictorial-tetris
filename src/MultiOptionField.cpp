#include <SFML/System/String.hpp>
#include <Button.h>
#include <Game.h>
#include "MultiOptionField.h"

MultiOptionField::MultiOptionField(float width, float height,
                                   const sf::String &text, unsigned int size,
                                   float percent)
        : Button(width * percent, height, text, size), percent(percent) {
    text_option.setFont(Game::getView().getFont());
    text_option.setFillColor(sf::Color::White);
    text_option.setCharacterSize(size);
}

void MultiOptionField::setPosition(float x, float y) {
    Button::setPosition(x, y);
    setTextOptionPosition();
}

void MultiOptionField::draw(sf::RenderTarget &target,
                            sf::RenderStates states) const {
    Button::draw(target, states);
    target.draw(text_option, states);
}

void MultiOptionField::addOption(const sf::String &option) {
    if (options.empty()) {
        options.push_back(option);
        setCurrent(0);
    } else {
        options.push_back(option);
    }
}

unsigned int MultiOptionField::selectNext() {
    if (!options.empty()) {
        selected_option = (selected_option + 1) % options.size();
        setCurrent(selected_option);
    }
    return selected_option;
}

unsigned int MultiOptionField::selectPrevious() {
    if (!options.empty()) {
        if (--selected_option < 0) selected_option += options.size();
        setCurrent(selected_option);
    }
    return selected_option;
}

void
MultiOptionField::setOptionString(unsigned int idx, const sf::String &s) {
    options[idx] = s;
    text_option.setString(options[idx]);
    setCurrent(selected_option);
}

void MultiOptionField::setCurrent(unsigned int idx) {
    selected_option = idx;
    text_option.setString(options[idx]);
}

bool MultiOptionField::setTextOptionPosition() {
    text_option.setPosition(
            getPosition() + sf::Vector2f(getSize().x + 15, 0));
    return true;
}
