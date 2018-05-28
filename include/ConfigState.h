#pragma once

#include <State.h>
#include <Button.h>
#include "MultiOptionField.h"

class ConfigState : public State {
public:
    ConfigState();

    void handleInput(sf::Event &event) override;
    void update(float dt) override;
    void render() override;

private:
    enum FIELDS {
        LEVEL,
        VBLOCKS,
        HBLOCKS,
        START
    };

    void selectNext();
    void selectPrevious();
    void selectLeft();
    void selectRight();
    void enter();

    const sf::Color COLOR_BACKGROUND{12, 24, 24};
    std::vector<MultiOptionField> fields;
    unsigned int selected{0};
};