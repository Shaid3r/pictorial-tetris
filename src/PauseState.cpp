//
// Created by th3r4tty on 10.06.18.
//

#include <State.h>
#include <PauseState.h>
#include <Game.h>
#include <MenuState.h>

void PauseState::handleInput(sf::Event &event) {
    if (event.type == sf::Event::EventType::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            Game::getGSM().pop();
        }
        else if(event.key.code == sf::Keyboard::Escape) {
            Game::getView().time = 0;
            Game::getGSM().set(std::make_unique<MenuState>());
        }
    }
}

void PauseState::update(float) {

}

void PauseState::render() {
    View &view = Game::getView();
    sf::RenderTarget &target = view.getWindow();
    target.clear(Game::getView().getBackgroundColor());

    sf::Text message( std::string(8, ' ') + std::string("GAME PAUSED\n") +
                     "ENTER - continue game\n" +
                     "       ESC - main menu", view.getFont(), 80);
    message.setStyle(sf::Text::Regular);

    message.setPosition(
            (view.getWidth() - message.getLocalBounds().width) / 2.f,
            (view.getHeight() - message.getLocalBounds().height) / 2.f);
    target.draw(message);
}
