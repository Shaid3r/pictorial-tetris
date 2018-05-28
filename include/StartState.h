#pragma once

#include "State.h"
#include "Button.h"

class StartState : public State {
public:
    StartState();

    void handleInput(sf::Event &event) override;
    void update(float dt) override;
    void render() override;

private:
    void selectNext();
    void selectPrevious();
    void enter();

    static const unsigned int BTN_WIDTH = 200;
    static const unsigned int BTN_HEIGHT = 45;
    static const std::string BTN_TXT;
    static const sf::Color COLOR_BACKGROUND;

    Button selectBtn;
    unsigned int selected{0};
};



