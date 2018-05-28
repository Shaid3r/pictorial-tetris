#pragma once

class Config {
public:
    void setVBlocks(unsigned int x);
    void setHBlocks(unsigned int x);
    unsigned int getVBlocks() const;
    unsigned int getHBlocks() const;
    enum LEVEL {
        EASY,
        NORMAL,
        HARD
    };

    static const int MIN_BLOCKS = 2;
    static const int MAX_BLOCKS = 50;

    LEVEL level = NORMAL;
private:
    unsigned int verticalBlocks = 4;
    unsigned int horizontalBlocks = 4;
};



