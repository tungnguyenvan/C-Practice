#include "vld.h"
#include <iostream>
#include "Virus.h"
#include <string>
#include <fstream>

using namespace std;

const string FILE_PATH = "ATGX.bin";
const int MAX_LENG = 255;
int lengthADN = 0;

Virus::Virus() {
	LoadADNInformation();
}

Virus::~Virus() {
	delete []this->m_dna;
}

Virus::Virus(const Virus &virus) {
	m_dna = new char[255];
	for (int i = 0; i < 255; i++) {
		this->m_dna[i] = virus.m_dna[i];
	}
	m_resistance = virus.m_resistance;
}

int Virus::GetResistance() {
	return this->m_resistance;
}

void Virus::SetResistance(int m_resistance) {
	this->m_resistance = m_resistance;
}

void Virus::LoadADNInformation() {
	string adn;
	ifstream file(FILE_PATH, ios::in);
	if (file.fail()) {
		cout << "cannot open file" << endl;
		return;
	}

	if (!file.eof()) {
		this->m_dna = new char[255];
		file >> this->m_dna;
	}
	file.close();
}
