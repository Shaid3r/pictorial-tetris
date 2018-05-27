#include <SFML/Window/Event.hpp>
#include <MenuState.h>
#include <iostream>
#include <ColorConverter.h>

#include "Game.h"
#include "StartState.h"

const sf::Color StartState::COLOR_BACKGROUND{12, 24, 24};
const std::string  StartState::BTN_TXT = "Select";

StartState::StartState() : selectBtn(BTN_WIDTH, BTN_HEIGHT, BTN_TXT) {
    selectBtn.setPosition((Game::getView().getWidth() - BTN_WIDTH) / 2,
                          Game::getView().getHeight() * 0.8);

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
            (view.getWidth() - title.getLocalBounds().width) / 2,
            view.getHeight() * 0.07);
    target.draw(title);
    target.draw(selectBtn);

    sf::Texture &texture = Game::getView().texture;

    if (!texture.loadFromImage(Game::getView().img))
        throw std::runtime_error("Cannot load image");

//    sf::Sprite sprite = ColorConverter::resize(texture, Game::getView().getWidth()* 0.5, Game::getView().getHeight()*0.5);
    sf::Sprite sprite = ColorConverter::resize(texture, 200, 400);


//    sprite.setTextureRect(sf::Rect(view.getWidth()/sprite.getLocalBounds().width, view.getHeight()/sprite.getLocalBounds().height);
//    sprite.setScale(view.getWidth()/sprite.getLocalBounds().width, view.getHeight()/sprite.getLocalBounds().height);
    sprite.setPosition(0, 200);
    target.draw(sprite);

//        updated = false;
//    }
}

void StartState::selectNext() {

}

void StartState::selectPrevious() {

}

void StartState::enter() {

}
