#pragma once

#include <stack>
#include <vector>

#include <State.h>
#include <View.h>
#include <Game.h>

/**
 * @brief Reprezentuje stan rozpoczęcia gry.
 */
class PlayState : public State {
public:
    /**
     * @brief Konstruuje PlayState.
     */
    PlayState();

    /**
     * @brief Przetwarza wejściowe zdarzenia pochodzące od użytkownika.
     *
     * @param event Zdarzenie pochodzące od użytkownika.
     */
    void handleInput(sf::Event &event) override;

    /**
     * @brief Aktualizuje aktualny stan.
     *
     * @param dt Czas renderowania i przetwarzania poprzedniej klatki gry.
     */
    void update(float dt) override;

    /**
     * @brief Renderuje stan gry.
     */
    void render() override;

private:
    void InitRedBounds(const View &view);
    void InitGreyPicture(View &view, const sf::Image &greyBackgroundImage);
    void InitRightPicture(View &view);
    void InitTimer(View &view);
    void InitBlocks();

    sf::Color toGrayscale(const sf::Color &color);
    sf::Sprite getFragment(int x, int y);

    void leftRotate();
    void rightRotate();

    float leftBegin = Game::getView().getWidth() * 0.075f;
    float topBegin = Game::getView().getHeight() * 0.35f;

    std::array<sf::RectangleShape, 3> redRectangle;
    double elementSiteLen;

    bool doubleSpeed = false;

    sf::Image image  = Game::getView().getTexture().copyToImage();

    sf::Sprite greyBackgroundSprite;
    sf::Texture greyBackgroundTexture;

    sf::Texture rightTexture;
    sf::Sprite rightSprite;

    std::vector<std::stack<sf::Sprite>> unplaced;
    sf::Sprite current;
    std::vector<sf::Sprite> placed;

    int rotation = 0;
    bool isCurrentPlaced = true;
    int currentColumn;
    int position;
    std::vector<int> stackHeight;

    sf::Text timeTitle;
};
