#pragma once
#include "Base.h"
#include <iostream>
using namespace std;

class Citizens : public Base
{
private:
    bool hasAMask;
    bool hasAVax;
    bool isInfected;
    time_t timeMask;
    time_t lifeTime;
public:
    Citizens();

    Citizens(int x, int y);

    void move(Graphics^ g);

    bool getHasAMask();

    void setHasAMask(bool v);

    bool getHasAVax();

    void setHasAVax(bool v);

    bool getIsInfected();

    void setIsInfected(bool v);

    time_t getTimeMask();

    void setTimeMask(time_t v);

    time_t getLifeTime();

    void setLifeTime(time_t v);

    ~Citizens();
};

