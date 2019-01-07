#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include <list>

using namespace std;

const bool DIE = true;
const bool ALIVE = false;

FluVirus::FluVirus() {
	DoBorn();
}

FluVirus::~FluVirus() {

}

FluVirus::FluVirus(const FluVirus *fluvirus) {
	*this = *fluvirus;
}

bool FluVirus::ReduceResistance(int medicine_resistance) {
	if (Virus::GetResistance() > 0) Virus::SetResistance(Virus::GetResistance() - medicine_resistance);
	if (Virus::GetResistance() < 0) return DIE;
	return ALIVE;
}

void FluVirus::DoBorn() {
	InitResistance();
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