#include "Config.h"

void Config::setVBlocks(unsigned int x) {
    if (x > MAX_BLOCKS)
        verticalBlocks = MIN_BLOCKS;
    else if (x < MIN_BLOCKS)
        verticalBlocks = MAX_BLOCKS;
    else
        verticalBlocks = x;
}

void Config::setHBlocks(unsigned int x) {
    if (x > MAX_BLOCKS)
        horizontalBlocks = MIN_BLOCKS;
    else if (x < MIN_BLOCKS)
        horizontalBlocks = MAX_BLOCKS;
    else
        horizontalBlocks = x;
}

unsigned int Config::getVBlocks() const {
    return verticalBlocks;
}

unsigned int Config::getHBlocks() const {
    return horizontalBlocks;
}
