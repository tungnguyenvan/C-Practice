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

DengueVirus::DengueVirus(const DengueVirus &dengueVirus) {
	for (int i = 0; i < 4; i++) {
		m_protein[i] = dengueVirus.m_protein[i];
	}
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
	DengueVirus *virus = this;
	return virus;
}

void DengueVirus::DoDie() {
	delete this;
}

void DengueVirus::InitResistance() {
	Virus::SetResistance(rand() % 30 + 1);
}