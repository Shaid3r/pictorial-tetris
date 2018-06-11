#include <State.h>
#include <Game.h>
#include <MenuState.h>
#include <GameOverState.h>
#include <cmath>

GameOverState::GameOverState() {
    Config& config = Game::getConfig();
    finalScore = (1000 * (config.level + 1) * pow(config.getBlocks(), 2)) / Game::getView().time;
}

GameOverState::~GameOverState() {

}

void GameOverState::handleInput(sf::Event &event) {
    if (event.type == sf::Event::EventType::KeyPressed) {
        if ( event.key.code == sf::Keyboard::Enter) {
            Game::getGSM().set(std::make_unique<MenuState>());
        }
    }
}

void GameOverState::update(float) {
    Game::getView().time = 0.0;
}

void GameOverState::render() {
    View &view = Game::getView();
    sf::RenderTarget &target = view.getWindow();
    target.clear(Game::getView().getBackgroundColor());

    sf::Text message(std::string("Final score: ") +
                     std::to_string(finalScore) + "\n" +
                     "Press ENTER to continue", view.getFont(), 80);
    message.setPosition(
            (view.getWidth() - message.getLocalBounds().width) / 2.f,
            (view.getHeight() - message.getLocalBounds().height) / 2.f);
    target.draw(message);
}

