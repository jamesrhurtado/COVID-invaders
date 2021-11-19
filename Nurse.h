#pragma once
#include "Base.h"
class Nurse :
    public Base
{
private:
    bool isBusy;

public:
    Nurse();
    Nurse(int x, int y);
    void move(Graphics^ g, char i);
    void setIsBusy(bool v);
    bool getIsBusy();
    ~Nurse();
};

