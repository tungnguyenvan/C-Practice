#include "DengueVirus.h"
#include <iostream>
#include <list>
#include "Virus.h"

using namespace std;

const bool DIE = true;
const bool ALIVE = false;

DengueVirus::DengueVirus() {

}

DengueVirus::DengueVirus(const DengueVirus &dengueVirus) {

}

DengueVirus::~DengueVirus() {

}

bool DengueVirus::ReduceResistance(int medicine_resistance) {
	if (Virus::GetResistance() > 0) Virus::SetResistance(Virus::GetResistance() - medicine_resistance);
	if (Virus::GetResistance() < 0) return DIE;
	return ALIVE;
}

void DengueVirus::DoBorn() {

}

void DengueVirus::DoClone(list<Virus*> listVirus) {

}

void DengueVirus::DoDie() {

}

void DengueVirus::InitResistance() {

}