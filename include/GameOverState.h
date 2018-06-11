#pragma once

#include <State.h>

class GameOverState : public State {
public:
    GameOverState();
    ~GameOverState() override;
    void handleInput(sf::Event &event) override;
    void update(float dt) override;
    void render() override;

private:
    int finalScore;
};
