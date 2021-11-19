#include "Mask.h"

Mask::Mask(){}

Mask::Mask(int x, int y) : Base(x, y, 1, 1, 0, 0){
	this->captured = false;
	this->elementType = 1;
	this->dy = dx = 10;
}

void Mask::move(Graphics^ g){

	if (x + dx + w > g->VisibleClipBounds.Width || x + dx < 1) {
		this->dx = 0;
	}

	this->x += this->dx;

	if (y + dy + h > g->VisibleClipBounds.Height || y + dy < 1) {
		this->dy = 0;
	}

	this->y += this->dy;

	this->animate();
}

Mask::~Mask(){}
