#pragma once

#include <SFML/Graphics.hpp>

class GameStateManager;

class State {
public:
    State(GameStateManager& gsm) : gsm(gsm) {}
    virtual ~State() {}

    virtual void handleInput(sf::Event &event) = 0;
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTarget &target) = 0;

protected:
    GameStateManager& gsm;
};