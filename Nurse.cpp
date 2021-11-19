#include "Nurse.h"

Nurse::Nurse(){}

Nurse::Nurse(int x, int y): Base(x, y, 4, 4, 0, 0){
	this->isBusy = false;
	this->dx = 0;
	this->dy = 0;
}
void Nurse::move(Graphics^ g, char i){
	this->dx = 0;
	this->dy = 0;
	switch (i) {
	case 'A':
		if (this->x > 0) {
			this->dx -= 5;
			//-
			this->x += this->dx;
			this->idy = 1;
		}
		break;

	case 'D':
		if (this->x + this->w * 1.0 < g->VisibleClipBounds.Width) {
			this->dx = 5;
			this->x += this->dx;
			this->idy = 2;
		}
		break;

	case 'W':
		if (this->y > 0) {
			this->dy = -5;
			//-
			this->y += this->dy;
			this->idy = 3;
		}
		break;

	case 'S':
		if (this->y + this->h * 1.0 < g->VisibleClipBounds.Height) {
			this->dy = 5;
			this->y += this->dy;
			this->idy = 0;
		}
		break;
	}

    this->animate();

}

void Nurse::setIsBusy(bool v){
    this->isBusy = v;
}

bool Nurse::getIsBusy(){
    return this->isBusy;
}




Nurse::~Nurse(){}