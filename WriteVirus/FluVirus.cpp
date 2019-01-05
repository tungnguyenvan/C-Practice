#include <iostream>
#include "FluVirus.h"
#include <list>

using namespace std;

FluVirus::FluVirus() {

}

FluVirus::~FluVirus() {

}

void FluVirus::ReduceResistance(int medicine_resistance, list<Virus*> *listVirus) {
	cout << "Flu virus reduce" << endl;
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