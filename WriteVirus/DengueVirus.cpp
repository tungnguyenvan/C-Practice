#include "vld.h"
#include "DengueVirus.h"
#include <iostream>
#include <list>
#include "Virus.h"

#include <cstdlib>
#include <ctime>

using namespace std;

const bool DIE = true;
const bool ALIVE = false;

DengueVirus::DengueVirus() {
	srand(NULL);
	DoBorn();
	cout << "this" << endl;
}

DengueVirus::DengueVirus(const DengueVirus *dengueVirus) : Virus(*dengueVirus) {
	this->m_protein = new char[4];
	for (int i = 0; i < 4; i++) {
		this->m_protein[i] = dengueVirus->m_protein[i];
	}
}

DengueVirus::~DengueVirus() {
	delete[]this->m_protein;
}

bool DengueVirus::ReduceResistance(int medicine_resistance) {
	if (Virus::GetResistance() > 0) Virus::SetResistance(Virus::GetResistance() - medicine_resistance);
	if (Virus::GetResistance() <= 0) return DIE;
	return ALIVE;
}

void DengueVirus::DoBorn() {
	InitResistance();
	int minProtein = 1;
	int maxProtein = 3;
	int randProtein = minProtein + rand() % (maxProtein - minProtein + 1);
	this->m_protein = new char[4];
	switch (randProtein) {
	case 1:
		this->m_protein[0] = 'N';
		this->m_protein[1] = 'S';
		this->m_protein[2] = '3';
		break;
	case 2:
		this->m_protein[0] = 'N';
		this->m_protein[1] = 'S';
		this->m_protein[2] = '5';
		break;
	case 3:
		this->m_protein[0] = 'E';
		break;
	}
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