#pragma once

#include <SFML/System/String.hpp>
#include "Button.h"

class MultiOptionField : public Button {
public:
    MultiOptionField(float width, float height, const sf::String &text="",
                     unsigned int size=30, float percent = 0.5);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void addOption(const sf::String &option);
    void setCurrent(unsigned int idx);

    void setPosition(float x, float y);
    void setOptionString(unsigned int idx, const sf::String &);

    unsigned int selectNext();
    unsigned int selectPrevious();

private:
    bool setTextOptionPosition();
    sf::Text text_option;
    std::vector<sf::String> options;
    int selected_option = 0;
    float percent;
};
