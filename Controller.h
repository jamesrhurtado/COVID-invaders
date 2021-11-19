#pragma once
#include "Citizens.h"
#include "Nurse.h"
#include "Mask.h"
#include "Vax.h"
#include "Virus.h"

class Controller 
{
private:
	Nurse* _nurse;
	vector<Virus*> arrVirus;
	vector<Citizens*>arrCitizens;
	vector<Base*> arrElements;
	int nDeaths;
	int nVaccinated;
	int nSurvivors;
	int lvl;
public:
	Controller(int nCitizens, int nVirus, int lvl);
	void drawNurse(Graphics^ g, Bitmap^ bmp);
	void moveNurse(Graphics^ g, char i);
	void drawCitizens(Graphics^ g, Bitmap^ bmpCitizen, Bitmap^ bmpInfected,
		Bitmap^ bmpCitizenMask, Bitmap^ bmpCitizenVax);
	void drawVirus(Graphics^ g, Bitmap^ bmp);
	void addMask();
	void addVax();
	void drawElements(Graphics^ g, Bitmap^ bmpMask, Bitmap^ bmpVax);
	void captureElements();
	void useElements();
	void infectCitizens();
	int getNDeaths();
	int getNVaccinated();
	int getNSurvivors();
	void countResults();
	void spreadAmongCitizens();

	~Controller();
};

