#include <SFML/Window/Event.hpp>
#include <MenuState.h>
#include <iostream>

#include "Game.h"
#include "StartState.h"
#include "ConfigState.h"

const sf::Color StartState::COLOR_BACKGROUND{12, 24, 24};
const std::string  StartState::BTN_TXT = "Select";

StartState::StartState() : selectBtn(BTN_WIDTH, BTN_HEIGHT, BTN_TXT) {
    selectBtn.setPosition((Game::getView().getWidth() - BTN_WIDTH) / 2,
                          Game::getView().getHeight() * 0.8);
    Game::getView().loadImg2Texture(0);
}

void StartState::handleInput(sf::Event &event) {
    if (event.type == sf::Event::EventType::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Escape:
                Game::getGSM().set(std::make_unique<MenuState>());
                break;
            case sf::Keyboard::Left:
                selectPrevious();
                break;
            case sf::Keyboard::Right:
                selectNext();
                break;
            case sf::Keyboard::Enter:
            case sf::Keyboard::Space:
                enter();
                break;
            default:
                break;
        }
    }
}

void StartState::update(float) {}

void StartState::render() {
//    if (updated) {
    View &view = Game::getView();
    sf::RenderTarget &target = view.getWindow();
    target.clear(COLOR_BACKGROUND);

    sf::Text title("Choose picture", view.getFont(), 40);
    title.setPosition(
            (view.getWidth() - title.getLocalBounds().width) / 2.f,
            view.getHeight() * 0.07f);
    target.draw(title);
    target.draw(selectBtn);

    sf::Sprite sprite = view.resize(view.getWidth() * 0.5f,
                                    view.getHeight() * 0.5f);
    sprite.setPosition(view.getWidth() * 0.25f, view.getHeight() * 0.2f);
    target.draw(sprite);
//        updated = false;
//    }
}

void StartState::selectNext() {
    selected = (selected + 1) % Game::getView().IMAGES_COUNT;
    Game::getView().loadImg2Texture(selected);
    updated = true;
}

void StartState::selectPrevious() {
    selected = (selected - 1) % Game::getView().IMAGES_COUNT;
    Game::getView().loadImg2Texture(selected);
    updated = true;
}

void StartState::enter() {
//    Game::getGSM().push(std::make_unique<ConfigState>());
}
