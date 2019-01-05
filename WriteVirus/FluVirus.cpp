#include <iostream>
#include "FluVirus.h"
#include <list>

using namespace std;

FluVirus::FluVirus() {

}

FluVirus::~FluVirus() {

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