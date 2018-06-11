#include <Game.h>
#include <State.h>
#include <GameStateManager.h>

void GameStateManager::handleInput(sf::Event &event) {
    states.top()->handleInput(event);
}

void GameStateManager::update(float dt) {
    states.top()->update(dt);
}

void GameStateManager::render() {
    states.top()->render();
}

void GameStateManager::pop() {
    states.pop();
}

void GameStateManager::push(std::unique_ptr<State> state) {
    states.push(std::move(state));
}

void GameStateManager::set(std::unique_ptr<State> state) {
    while (!states.empty())
        pop();

    states.push(std::move(state));
}
