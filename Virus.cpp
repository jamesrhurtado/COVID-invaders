#include "Virus.h"
Virus::Virus(){}

Virus::Virus(int x, int y, int lvl): Base(x, y, 1, 1, 0, 0) {
    System::Random^ r = gcnew System::Random();
    if (lvl == 1) {
        dx = r->Next(-5, 5);
        dy = r->Next(-5, 5);
    }
    else if (lvl == 2) {
        dx = r->Next(-8, 8) + 7;
        dy = r->Next(-8, 8) + 7;
    }
    delete r;
}

void Virus::move(Graphics^ g) {
    if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) {
        dx = dx * -1;
    }
    this->x += this->dx;
    if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height) {
        dy = dy * -1;
    }
    this->y += this->dy;

}
Virus::~Virus() {}
