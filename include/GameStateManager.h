#pragma once

#include <memory>
#include <stack>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <State.h>


class GameStateManager {
public:
    void handleInput(sf::Event &event);
    void update(float dt);
    void render();

    void push(std::unique_ptr<State> state);
    void pop();
    void set(std::unique_ptr<State> state);

private:
	std::stack<std::unique_ptr<State>> states;
};
