#include "MenuState.h"
#include "GameStateManager.h"

MenuState::MenuState(GameStateManager &gsm) : State(gsm) {}

MenuState::~MenuState() {

}

void MenuState::handleInput(sf::Event &event) {

}

void MenuState::render(sf::RenderTarget &target) {
    target.draw(sf::CircleShape(30));
}

void MenuState::update(float dt) {

}
