#pragma once

#include "State.h"
#include "Button.h"

class MenuState : public State {
public:
    MenuState(GameStateManager &gsm);

    void handleInput(sf::Event &event) override;
    void update(float dt) override;
    void render(sf::RenderTarget &target) override;

    void selectNext();
    void selectPrevious();

private:
    enum BUTTONS {
        START,
        HELP,
        TOP10,
        EXIT
    };

    const sf::Color COLOR_BACKGROUND{12, 24, 24};
    std::vector<Button> buttons;
    unsigned int selected{0};

    void enter();
};