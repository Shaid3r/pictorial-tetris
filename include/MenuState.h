#pragma once

#include "State.h"

class MenuState : public State {
public:
    MenuState(GameStateManager &gsm);
    ~MenuState() override;

    void handleInput(sf::Event &event) override;
    void update(float dt) override;
    void render(sf::RenderTarget &target) override;
};