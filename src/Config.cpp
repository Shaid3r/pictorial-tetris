#include <Game.h>
#include "Config.h"

void Config::setVBlocks(unsigned int x) {
    if (x > MAX_BLOCKS)
        verticalBlocks = MIN_BLOCKS;
    else if (x < MIN_BLOCKS)
        verticalBlocks = MAX_BLOCKS;
    else
        verticalBlocks = x;
}



unsigned int Config::getVBlocks() const {
    return verticalBlocks;
}

double Config::getVelocity() const {
    return (velocity + level) * Game::getView().getHeight() / 5.0;
}

