#include <iostream>
#include <list>
#include "Patient.h"
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"

using namespace std;

enum LifePtient
{
	DIE,
	ALIVE
};

Patient::Patient() {
	DoStart();
}

Patient::~Patient() {
	cout << ":( Patient is Die :(" << endl;
}

list<Virus*> Patient::GetListVirus() {
	return this->m_VirusList;
}

void Patient::DoStart() {
	this->m_state = ALIVE;
	this->m_resistance = rand() % 8001 + 1000;

	int maxVirus = rand() % 11 + 10;
	Virus *virus;
	for (int i = 0; i < maxVirus; i++) {
		if (rand() % 2 == 0)  virus = new FluVirus();
		else virus = new DengueVirus();

		this->m_VirusList.push_back(virus);
	}
}

void Patient::TakeMadicine() {

}

void Patient::ReduceResistance(int medicine_resistance) {
	if (this->m_resistance <= 0) DoDie();
}

void Patient::DoDie() {
	this->m_state = DIE;
}

int Patient::GetState() {
	return this->m_state;
}