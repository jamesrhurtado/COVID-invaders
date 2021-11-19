#pragma once
#include "Base.h"
class Vax : public Base
{
private:

public:
	Vax();
	Vax(int x, int y);
	void move(Graphics^ g);
	~Vax();
};

