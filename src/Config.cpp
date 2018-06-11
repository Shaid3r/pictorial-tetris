#include <Game.h>
#include <Config.h>

void Config::setBlocks(unsigned int x) {
    if (x > MAX_BLOCKS)
        blocks = MIN_BLOCKS;
    else if (x < MIN_BLOCKS)
        blocks = MAX_BLOCKS;
    else
        blocks = x;
}

unsigned int Config::getBlocks() const {
    return blocks;
}

double Config::getVelocity() const {
    return (velocity + level) * Game::getView().getHeight() / 5.0;
}
