#include "vld.h"
#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include <list>

#include <cstdlib>
#include <ctime>

using namespace std;

const bool DIE = true;
const bool ALIVE = false;

FluVirus::FluVirus() {
	srand(NULL);
	DoBorn();
}

FluVirus::~FluVirus() {

}

FluVirus::FluVirus(const FluVirus *fluvirus) : Virus(*fluvirus) {
	this->m_color = fluvirus->m_color;
}

bool FluVirus::ReduceResistance(int medicine_resistance) {
	if (Virus::GetResistance() > 0) Virus::SetResistance(Virus::GetResistance() - medicine_resistance);
	if (Virus::GetResistance() <= 0) return DIE;
	return ALIVE;
}

void FluVirus::DoBorn() {
	InitResistance();
	if (rand() % 2 == 0) this->m_color = 0x0000ff; //is blue
	else this->m_color = 0xff0000;
}

Virus *FluVirus::DoClone() {
	Virus *virus = new FluVirus(this);
	return virus;
}

void FluVirus::DoDie() {
	delete this;
}

void FluVirus::InitResistance() {
	Virus::SetResistance(rand() % 30 + 1);
}