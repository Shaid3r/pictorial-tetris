#include <Game.h>
#include <State.h>
#include <HelpState.h>


void HelpState::handleInput(sf::Event &event) {
    if (event.type == sf::Event::EventType::KeyPressed) {
        if (event.type == sf::Event::EventType::KeyPressed &&
            event.key.code == sf::Keyboard::Escape) {
            Game::getGSM().pop();
        }
    }
}

void HelpState::update(float) {}

void HelpState::render() {
    View &view = Game::getView();
    sf::RenderTarget &target = view.getWindow();
    target.clear(Game::getView().getBackgroundColor());

    sf::Text message(std::string(28, ' ') + "Menu:\n"
                      "UP, DOWN, LEFT, RIGHT - moving\n" +
                      std::string(22, ' ') + "ENTER - select\n" +
                      std::string(27, ' ') + "ESC - back\n\n" +
                      std::string(28, ' ') + "Game:\n" + std::string(4, ' ') +
                      "LEFT, RIGHT  - change position\n" + std::string(18, ' ') +
                      "DOWN - speed x10\n" +
                      std::string(25, ' ') + "Z, X - rotate\n" +
                      std::string(27, ' ') + "P - pause", view.getFont(), 40);
    message.setPosition(
            (view.getWidth() - message.getLocalBounds().width) / 2.f,
            (view.getHeight() - message.getLocalBounds().height) / 2.f);
    target.draw(message);
}
