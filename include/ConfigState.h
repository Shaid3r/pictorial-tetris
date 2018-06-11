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
        BLOCKS,
        START
    };

    void selectNext();
    void selectPrevious();
    void selectLeft();
    void selectRight();
    void enter();

    std::vector<MultiOptionField> fields;
    int selected{0};
};