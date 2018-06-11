#include <PlayState.h>
#include <Game.h>
#include <iostream>
#include <GameOverState.h>
#include <cmath>
#include <PauseState.h>

PlayState::PlayState() {
    View& view = Game::getView();
    image = view.getTexture().copyToImage();
    sf::Image greyBackgroundImage = view.getTexture().copyToImage();

    for (int i = 0; i < greyBackgroundImage.getSize().y; ++i)
        for (int j = 0; j < greyBackgroundImage.getSize().x; ++j)
            greyBackgroundImage.setPixel(
                    j, i, toGrayscale(greyBackgroundImage.getPixel(j, i))
            );

    InitRightPicture(view);
    InitGreyPicture(view, greyBackgroundImage);
    InitBlocks();
    InitRedBounds(view);
    InitTimer(view);
}

void PlayState::handleInput(sf::Event &event) {
    Config& config = Game::getConfig();
    if (event.type == sf::Event::EventType::KeyPressed) {
        int ht;
        switch (event.key.code) {
            case sf::Keyboard::Left:
                position -= 1;
                 ht = config.getBlocks() - stackHeight[position] - 1;
                if (position < 0 ||
                    current.getPosition().y >= topBegin + elementSiteLen * ht) {
                    position += 1;
                }
                break;
            case sf::Keyboard::Right:
                position += 1;
                ht = config.getBlocks() - stackHeight[position] - 1;
                if (position > config.getBlocks() - 1 ||
                    current.getPosition().y > topBegin + elementSiteLen * ht) {
                    position -= 1;
                }
                break;
            case sf::Keyboard::Down:
                doubleSpeed = true;
                break;
            case sf::Keyboard::X:
                rightRotate();
                break;
            case sf::Keyboard::Z:
                leftRotate();
                break;
            case sf::Keyboard::P:
                Game::getGSM().push(std::make_unique<PauseState>());

            default:
                    break;

        }
    }
}

void PlayState::update(float dt) {
    Config& config = Game::getConfig();

    if (isCurrentPlaced) {
        do {
            currentColumn = rand() % config.getBlocks();
        } while(unplaced[currentColumn].empty());

        current = unplaced[currentColumn].top();
        position = config.getBlocks() / 2.0d;
        current.setPosition(leftBegin + position * elementSiteLen,
                            - elementSiteLen);
        rotation = 0;
        for (int i = 0; i < rand() % 3 + 1; ++i)
            rightRotate();

        isCurrentPlaced = false;
    }
    else {
        int ht = config.getBlocks() - stackHeight[position] - 1;
        double speed = doubleSpeed ?
                       10 * config.getVelocity() : config.getVelocity();
        current.setPosition(leftBegin + position * elementSiteLen,
                            current.getPosition().y + speed * dt);

        if (current.getPosition().y >= topBegin + elementSiteLen * ht &&
            currentColumn == position && rotation == 0) {
            current.setPosition(leftBegin + currentColumn * elementSiteLen,
                                topBegin + elementSiteLen * ht);
            placed.push_back(current);
            stackHeight[currentColumn] += 1;
            isCurrentPlaced = true;
            doubleSpeed = false;
            unplaced[currentColumn].pop();
            if (placed.size() == pow(config.getBlocks(), 2)) {
                Game::getGSM().push(std::make_unique<GameOverState>());
            }
        }
        else if (current.getPosition().y >= topBegin + elementSiteLen * ht &&
                 (currentColumn != position || rotation != 0)) {
            isCurrentPlaced = true;
            doubleSpeed = false;
        }
    }

    Game::getView().time += dt;
}

void PlayState::render() {
    sf::RenderTarget &target = Game::getView().getWindow();
    target.clear(Game::getView().getBackgroundColor());
    target.draw(greyBackgroundSprite);
    target.draw(rightSprite);
    target.draw(current);

    for (auto it : placed)
        target.draw(it);

    for (auto it : redRectangle)
        target.draw(it);

    target.draw(timeTitle);

    auto seconds = static_cast<int>(Game::getView().time);
    int hours = seconds / 3600;
    seconds -= hours * 3600;
    int minutes = seconds / 60;
    seconds -= minutes * 60;

    timeTitle.setString(std::string("Time: ") +
                        (hours > 9 ? std::to_string(hours) : std::string("0") +
                        std::to_string(hours)) + ":" +
                        (minutes > 9 ?
                        std::to_string(minutes) : std::string("0") +
                        std::to_string(minutes)) + ":" +
                        (seconds > 9 ?
                        std::to_string(seconds) : std::string("0") +
                        std::to_string(seconds))
    );
}

sf::Color PlayState::toGrayscale(const sf::Color &color) {
    auto avg = static_cast<sf::Uint8>(
            color.r * 0.12f + color.g * 0.72f + color.b * 0.07f);
    return {avg, avg, avg};
}

sf::Sprite PlayState::getFragment(int i, int j) {
    double w = Game::getView().getTexture().getSize().x;
    double h = Game::getView().getTexture().getSize().y;
    int nrOfEl = Game::getConfig().getBlocks();
    double d = w < h ? w / nrOfEl : h / nrOfEl;

    elementSiteLen = d * greyBackgroundSprite.getScale().x;

    int widthOffset, heightOffset;
    if (w > h) {

        widthOffset = (w - h) / 2;
        heightOffset = 0;
    }
    else if(h > w) {
        heightOffset = (h - w) / 2;
        widthOffset = 0;
    }
    else {
        widthOffset = 0;
        heightOffset = 0;
    }

    sf::Sprite sprite(Game::getView().getTexture());
    sprite.setTextureRect(sf::IntRect(widthOffset + j * d,
                                      heightOffset + i * d, d, d));
    sprite.setScale(greyBackgroundSprite.getScale());

    return sprite;
}

void PlayState::InitBlocks() {
    Config& config = Game::getConfig();
    unplaced.resize(Game::getConfig().getBlocks());
    stackHeight.resize(config.getBlocks());
    for (unsigned int i = 0; i < config.getBlocks(); ++i) {
        stackHeight[i] = 0;
        for (unsigned int j = 0; j < config.getBlocks(); ++j)
            unplaced[j].push(getFragment(i, j));
    }
}

void PlayState::rightRotate() {
    double origin = elementSiteLen / current.getScale().x;
    if (rotation == 0) {
        current.rotate(90);
        current.setOrigin(0, origin);
    }
    else if (rotation == 1) {
        current.rotate(90);
        current.setOrigin(origin, origin);

    }
    else if (rotation == 2) {
        current.rotate(90);
        current.setOrigin(origin, 0);

    }
    else if (rotation == 3) {
        current.rotate(90);
        current.setOrigin(0, 0);
    }
    rotation = (rotation + 1) % 4;

}

void PlayState::leftRotate() {
    for (int i = 0; i < 3; ++i)
        rightRotate();
}


void PlayState::InitTimer(View &view) {
    timeTitle = sf::Text(std::__cxx11::string("Time: 00:00:00") ,
                         view.getFont(), 60);
    timeTitle.setPosition(
            view.getWidth() - timeTitle.getLocalBounds().width * 1.4f,
            view.getHeight() * 0.07f);
}

void PlayState::InitRightPicture(View &view) {
    rightTexture.loadFromImage(image);
    rightSprite = view.resize(rightTexture, view.getWidth() * 0.35f,
                              view.getWidth() * 0.35f);
    rightSprite.setPosition(view.getWidth() * 0.5f + leftBegin, topBegin);
}

void PlayState::InitGreyPicture(View &view,
                                const sf::Image &greyBackgroundImage) {
    greyBackgroundTexture.loadFromImage(greyBackgroundImage);

    greyBackgroundSprite = view.resize(greyBackgroundTexture,
                                       view.getWidth() * 0.35f,
                                       view.getWidth() * 0.35f);
    greyBackgroundSprite.setPosition(leftBegin, topBegin);
}

void PlayState::InitRedBounds(const View &view) {
    for (int i = 0; i < 2; ++i) {
        redRectangle[i].setPosition(view.getWidth() * 0.0025f,
                                    view.getHeight() * 0.005f);
        redRectangle[i].setSize(
                sf::Vector2f(view.getWidth() * (i ? 0.51f : 0.995f),
                             view.getHeight() * 0.99f));
    }

    redRectangle[2].setPosition(leftBegin, 0);
    redRectangle[2].setSize(
            sf::Vector2f(elementSiteLen * Game::getConfig().getBlocks(),
                         elementSiteLen * Game::getConfig().getBlocks() +
                         topBegin));

    for (auto& it : redRectangle) {
        it.setOutlineColor(sf::Color(255, 0, 0));
        it.setFillColor(sf::Color(0, 0, 0, 0));
        it.setOutlineThickness(3);
    }
}
