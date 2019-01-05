#include <iostream>
#include "Virus.h"
#include <string>
#include <fstream>

using namespace std;

const string FILE_PATH = "ATGX.bin";
const int MAX_LENG = 255;
int lengthADN = 0;

Virus::Virus() {
	this->m_resistance = rand() % 30 + 1;
}

Virus::~Virus() {

}

Virus::Virus(const Virus &virus) {
	this->m_dna = virus.m_dna;
	this->m_resistance = virus.m_resistance;
}

void Virus::LoadADNInformation() {
	string adn;
	ifstream file(FILE_PATH, ios::in);
	if (file.fail()) {
		cout << "cannot open file" << endl;
		return;
	}

	if (!file.eof()) {
		file >> adn;
	}
	this->m_dna = const_cast<char*>(adn.c_str());
}

void Virus::ReduceResistance(int medicine_resistance, list<Virus*> *listVirus) {
	this->m_resistance -= medicine_resistance;
	if (this->m_resistance <= 0) delete this;
}
