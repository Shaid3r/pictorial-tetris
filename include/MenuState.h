#pragma once

#include "State.h"
#include "Button.h"

class MenuState : public State {
public:
    MenuState();

    void handleInput(sf::Event &event) override;
    void update(float dt) override;
    void render() override;

private:
    void selectNext();
    void selectPrevious();
    void enter();

    enum BUTTONS {
        START,
        HELP,
        TOP10,
        EXIT
    };

    std::vector<Button> buttons;
    unsigned int selected{0};
};