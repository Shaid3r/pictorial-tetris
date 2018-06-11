#pragma once

class Config {
public:
    void setVBlocks(unsigned int x);
    unsigned int getVBlocks() const;
    enum LEVEL {
        EASY,
        NORMAL,
        HARD
    };

    static const int MIN_BLOCKS = 2;
    static const int MAX_BLOCKS = 10;
    double getVelocity() const;
    LEVEL level = NORMAL;
private:
    float velocity = 0.5;
    unsigned int verticalBlocks = 4;
};



