#include "Controller.h"

Controller::Controller(int nCitizens, int nVirus, int lvl) {
	this->lvl = lvl;
	nDeaths = 0;
	nVaccinated = 0;
	nSurvivors = 0;
	System::Random^ r = gcnew System::Random();
	_nurse = new Nurse(20,20);
	for (int i = 0; i < nVirus; i++) {
		arrVirus.push_back(new Virus(r->Next(1, 1000), r->Next(1, 650), lvl));
	}
	for (int i = 0; i < nCitizens; i++) {
		arrCitizens.push_back(new Citizens(r->Next(1, 1000), r->Next(1, 650)));
		_sleep(100);
	}
	delete r;
}

void Controller::drawNurse(Graphics^ g, Bitmap^ bmp){
	_nurse->drawFromImage(g, bmp);
}

void Controller::moveNurse(Graphics^ g, char i) {
	_nurse->move(g, i);
	//moving elements just when the nurse hs captured them
	for (int i = 0; i < arrElements.size(); i++) {
		if (arrElements.at(i)->getIsCaptured() == true) {
			arrElements.at(i)->setDx(_nurse->getDx());
			arrElements.at(i)->setDy(_nurse->getDy());
			arrElements.at(i)->move(g);
		}
	}
}

void Controller::drawCitizens(Graphics^ g, Bitmap^ bmpCitizen, Bitmap^ bmpInfected,
	Bitmap^ bmpCitizenMask, Bitmap^ bmpCitizenVax) {

	for (int i = 0; i < arrCitizens.size(); i++) {
		//infected citizens
		if (arrCitizens.at(i)->getIsInfected()) {
			arrCitizens.at(i)->drawFromImage(g, bmpInfected);
			if (difftime(time(0), arrCitizens.at(i)->getLifeTime()) >= 10) {
				arrCitizens.at(i)->setRemove(true);
				nDeaths++;
			}
		} else if (arrCitizens.at(i)->getHasAMask()) {
			arrCitizens.at(i)->drawFromImage(g, bmpCitizenMask);
			if (difftime(time(0), arrCitizens.at(i)->getTimeMask()) >= 10) {
				arrCitizens.at(i)->setHasAMask(false);
			}
		} else if (arrCitizens.at(i)->getHasAVax()) {
			arrCitizens.at(i)->drawFromImage(g, bmpCitizenVax);
		} else {
			arrCitizens.at(i)->drawFromImage(g, bmpCitizen);
		}
		arrCitizens.at(i)->move(g);
	}


		//death citizens
	for (int i = 0; i < arrCitizens.size(); i++) {
		if (arrCitizens.at(i)->getRemove()) {
			arrCitizens.erase(arrCitizens.begin() + i);
		}
	}
}

void Controller::drawVirus(Graphics^ g, Bitmap^ bmp) {
	for (int i = 0; i < arrVirus.size(); i++) {
		arrVirus.at(i)->drawFromImage(g, bmp);
		arrVirus.at(i)->move(g);
	}
}

void Controller::addMask() {
	System::Random^ r = gcnew System::Random();
	arrElements.push_back(new Mask(r->Next(1, 1100), r->Next(1, 670)));
	delete r;
}

void Controller::addVax() {
	System::Random^ r = gcnew System::Random();
	arrElements.push_back(new Vax(r->Next(1, 1000), r->Next(1, 650)));
	delete r;
}

void Controller::drawElements(Graphics^ g, Bitmap^ bmpMask, Bitmap^ bmpVax){
	for (int i = 0; i < arrElements.size(); i++) {
		if (arrElements.at(i)->getElementType() == 1) {
			bmpMask->MakeTransparent(Color::White);
			arrElements.at(i)->drawFromImage(g, bmpMask);
		}

		if (arrElements.at(i)->getElementType() == 2) {
			arrElements.at(i)->drawFromImage(g, bmpVax);
		}
	}

	for (int i = 0; i < arrElements.size(); i++) {
		if (arrElements.at(i)->getRemove()) {
			arrElements.erase(arrElements.begin() + i);
		}
	}


}

void Controller::captureElements() {
	bool res = false;
	if (!_nurse->getIsBusy()) {
		for (int i = 0; !res && i < arrElements.size(); i++) {
			res = arrElements.at(i)->getRectangle().IntersectsWith(_nurse->getRectangle());
			if (res) {
				arrElements.at(i)->setIsCaptured(true);
				arrElements.at(i)->setDx(_nurse->getDx());
				arrElements.at(i)->setDy(_nurse->getDy());
				_nurse->setIsBusy(true);
			}
		}
	} else  {
		for (int i = 0; !res && i < arrElements.size(); i++) {
			res = arrElements.at(i)->getRectangle().IntersectsWith(_nurse->getRectangle());
			if (res) {
				arrElements.at(i)->setIsCaptured(false);
				arrElements.at(i)->setDx(0);
				arrElements.at(i)->setDy(0);
				_nurse->setIsBusy(false);
			}
		}
	}
}

void Controller::useElements() {
	bool flag = false;
	for (int i = 0; i < arrCitizens.size(); i++) {
		for (int j = 0; !flag && j < arrElements.size(); j++) {
			if (arrElements.at(j)->getRectangle().IntersectsWith(arrCitizens.at(i)->getRectangle())) {
				//checks if element has been captured
				if (arrElements.at(j)->getIsCaptured()) {
					flag = true;
					if (!arrCitizens.at(i)->getHasAMask() && !arrCitizens.at(i)->getHasAVax()) {
						if (arrElements.at(j)->getElementType() == 1) {
							arrCitizens.at(i)->setHasAMask(true);
							arrCitizens.at(i)->setTimeMask(time(0));
							_nurse->setIsBusy(false);
							arrElements.at(j)->setRemove(true);
						}
					}
					if (!arrCitizens.at(i)->getHasAVax()) {
						if (arrElements.at(j)->getElementType() == 2) {
							arrCitizens.at(i)->setHasAVax(true);
							arrCitizens.at(i)->setIsInfected(false);
							_nurse->setIsBusy(false);
							arrElements.at(j)->setRemove(true);
							this->nVaccinated++;
						}
					}
				}
			}
		}
	}
}
void Controller::infectCitizens() {
	for (int i = 0; i < arrCitizens.size(); i++) {
		for (int j = 0; j < arrVirus.size(); j++) {
			if (arrCitizens.at(i)->getRectangle().IntersectsWith(arrVirus.at(j)->getRectangle())) {
				if (!(arrCitizens.at(i)->getHasAMask() || arrCitizens.at(i)->getHasAVax())) {
					arrCitizens.at(i)->setIsInfected(true);
					arrCitizens.at(i)->setLifeTime(time(0));
				}
			}
		}
	}
}

int Controller::getNDeaths() {
	return this->nDeaths;
}

int Controller::getNVaccinated() {
	return this->nVaccinated;
}

int Controller::getNSurvivors() {
	return this->nSurvivors;
}

void Controller::countResults() {
	for (int i = 0; i < arrCitizens.size(); i++) {
		//los muertos son quitados del arreglo en el metodo dibujar
		//contamos aquellos q no han sido vacunados
		if (!arrCitizens.at(i)->getHasAVax()) {
			nSurvivors++;
		}
	}
}

void Controller::spreadAmongCitizens() {
	for (int i = 0; i < arrCitizens.size()-1; i++) {
		for (int j = i + 1; j < arrCitizens.size(); j++) {
			if (arrCitizens.at(i)->getRectangle().IntersectsWith(arrCitizens.at(j)->getRectangle())) {
				if (arrCitizens.at(i)->getIsInfected() || arrCitizens.at(j)->getIsInfected()) {
					if (!arrCitizens.at(i)->getIsInfected() &&
						(!(arrCitizens.at(i)->getHasAMask() || arrCitizens.at(i)->getHasAVax()))) {
						arrCitizens.at(i)->setIsInfected(true);
						arrCitizens.at(i)->setLifeTime(time(0));
					}
					if (!arrCitizens.at(j)->getIsInfected() &&
						(!(arrCitizens.at(j)->getHasAMask() || arrCitizens.at(j)->getHasAVax()))) {
						arrCitizens.at(j)->setIsInfected(true);
						arrCitizens.at(j)->setLifeTime(time(0));
					}
				}
			}
		}
	}
}



Controller::~Controller(){
	delete _nurse;
	for (int i = 0; i < arrVirus.size(); i++) {
		delete arrVirus.at(i);
	}
	arrVirus.clear();
}