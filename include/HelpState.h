#pragma once

#include "State.h"

class HelpState : public State {
public:
    HelpState() = default;

    ~HelpState() override;

    void handleInput(sf::Event &event) override;

    void update(float dt) override;

    void render() override;

private:

};