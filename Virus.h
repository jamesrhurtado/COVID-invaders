#pragma once
#include "Base.h"
class Virus :
    public Base
{
private:
public:
    Virus();
    Virus(int x, int y, int lvl);
    void move(Graphics^ g);
    ~Virus();

};

