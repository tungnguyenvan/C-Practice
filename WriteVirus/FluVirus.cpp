#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include <list>

using namespace std;

const bool DIE = true;
const bool ALIVE = false;

FluVirus::FluVirus() {

}

FluVirus::~FluVirus() {

}

bool FluVirus::ReduceResistance(int medicine_resistance) {
	cout << "Flu virus reduce" << endl;
	return ALIVE;
}

void FluVirus::DoBorn() {
	cout << "New Virus was born!" << endl;
}

void FluVirus::DoClone(list<Virus*> listVirus) {

}

void FluVirus::DoDie() {
	cout << "is Die" << endl;
}

void FluVirus::InitResistance() {

}