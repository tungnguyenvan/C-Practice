#include <iostream>
#include <list>
#include "Patient.h"
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"

using namespace std;

int resistanceVirus = 0;

enum Reistance
{
	MIN_RESISTANCE = 1000,
	MAX_RESISTANCE = 9000
};

enum TotalVirus
{
	MIN_VIRUS = 10,
	MAX_VIRUS = 20
};

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

int Patient::GetResistance() {
	return this->m_resistance;
}

int Patient::GetTotalResistanceVirus() {
	return resistanceVirus;
}

void Patient::DoStart() {
	this->m_state = ALIVE;
	InitResistance();

	int maxVirus = rand() % (MAX_VIRUS - MIN_VIRUS + 1) + MIN_VIRUS;
	Virus *virus;
	for (int i = 0; i < maxVirus; i++) {
		if (rand() % 2 == 0)  virus = new FluVirus();
		else virus = new DengueVirus();
		this->m_VirusList.push_back(virus);
		resistanceVirus += virus->GetResistance();
	}
}

void Patient::InitResistance() {
	this->m_resistance = rand() % (MAX_RESISTANCE - MIN_RESISTANCE + 1) + MIN_RESISTANCE;
}

void Patient::TakeMadicine(int medicine_resistance) {
	resistanceVirus = 0;
	list<Virus*>::iterator i = this->m_VirusList.begin();
	while (i != this->m_VirusList.end()) {
		if ((*i)->ReduceResistance(medicine_resistance)) {
			(*i)->DoDie();
			i = this->m_VirusList.erase(i);
		}
		else {
			//this->m_VirusList.push_back((*i)->DoClone());
			resistanceVirus += (*i)->GetResistance();
			++i;
		}
	}


	if (resistanceVirus > this->m_resistance) this->DoDie();
}

void Patient::ReduceResistance(int medicine_resistance) {
	if (this->m_resistance <= 0) DoDie();
}

void Patient::DoDie() {
	this->m_state = DIE;
	this->m_VirusList.clear();
}

int Patient::GetState() {
	return this->m_state;
}