#pragma once

#include <State.h>

class PauseState : public State {
public:
    PauseState() = default;

    ~PauseState() override = default;

    void handleInput(sf::Event &event) override;

    void update(float dt) override;

    void render() override;

};
