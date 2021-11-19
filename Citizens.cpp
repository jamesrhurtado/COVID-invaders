#include "Citizens.h"

Citizens::Citizens(){}
Citizens::Citizens(int x, int y) : Base(x, y, 4, 4, 0,0 ){
    timeMask = time(0);
    lifeTime = time(0);
    System::Random^ r = gcnew System::Random();
    dx = r->Next(-10, 10);
    this->hasAMask = false;
    this->hasAVax = false;
    this->isInfected = false;
    if (dx > 0) {
        dy = 0;
    }
    if (dx < 0) {
        dy = r->Next(5, 10);
        dx = 0;
    }
    delete r;
}

void Citizens::move(Graphics^ g) {
    if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) {
        dx = dx * -1;
    }
    if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height) {
        dy = dy * -1;
    }
    if (dx < 0) { idy = 1; }
    if (dx > 0) { idy = 2; }
    if (dy > 0) { idy = 0; }
    if (dy < 0) { idy = 3; }
    x = x + dx;
    y = y + dy;

    this->animate();
}



bool Citizens::getHasAMask() {
    return this->hasAMask;
}

void Citizens::setHasAMask(bool v) {
    this->hasAMask = v;
}

bool Citizens::getHasAVax() {
    return this->hasAVax;
}

void Citizens::setHasAVax(bool v) {
    this->hasAVax = v;
}

bool Citizens::getIsInfected() {
    return this->isInfected;
}

void Citizens::setIsInfected(bool v) {
    this->isInfected = v;
}

time_t Citizens::getTimeMask() {
    return timeMask;
}

void Citizens::setTimeMask(time_t v) {
    this->timeMask = v;
}

time_t Citizens::getLifeTime() {
    return lifeTime;
}

void Citizens::setLifeTime(time_t v) {
    this->lifeTime = v;
}

Citizens::~Citizens(){}
