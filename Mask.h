#pragma once
#include "Base.h"
class Mask :
    public Base
{
private:

public:
    Mask();
    Mask(int x, int y);
    void move(Graphics^ g);
    ~Mask();

};

