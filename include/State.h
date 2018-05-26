#pragma once

#include <SFML/Graphics.hpp>

class State {
public:
    State() = default;
    virtual ~State() {}

    virtual void handleInput(sf::Event &event) = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;

protected:
    bool updated{true};
};