#include "DengueVirus.h"
#include <iostream>
#include <list>
#include "Virus.h"

using namespace std;

const bool DIE = true;
const bool ALIVE = false;

DengueVirus::DengueVirus() {
	DoBorn();
}

DengueVirus::DengueVirus(const DengueVirus *dengueVirus) {
	*this = *dengueVirus;
}

DengueVirus::~DengueVirus() {

}

bool DengueVirus::ReduceResistance(int medicine_resistance) {
	if (Virus::GetResistance() > 0) Virus::SetResistance(Virus::GetResistance() - medicine_resistance);
	if (Virus::GetResistance() < 0) return DIE;
	return ALIVE;
}

void DengueVirus::DoBorn() {
	InitResistance();
}

DengueVirus *DengueVirus::DoClone() {
	DengueVirus *virus = new DengueVirus(this);
	return virus;
}

void DengueVirus::DoDie() {
	delete this;
}

void DengueVirus::InitResistance() {
	Virus::SetResistance(rand() % 30 + 1);
}