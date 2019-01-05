#include <iostream>
#include "Virus.h"
#include <string>
#include <fstream>

using namespace std;

const string FILE_PATH = "ATGX.bin";
const int MAX_LENG = 255;
int lengthADN = 0;

Virus::Virus() {

}

Virus::~Virus() {

}

Virus::Virus(const Virus &virus) {

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

void Virus::ReduceResistance(int medicine_resistance) {

}
