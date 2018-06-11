#pragma once

class Config {
public:
    void setBlocks(unsigned int x);
    unsigned int getBlocks() const;
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
    const float velocity = 0.5;
    unsigned int blocks = 4;
};



