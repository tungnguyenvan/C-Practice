#ifndef __PATIENT_H__
#define __PATIENT_H__
#include <list>
#include "Virus.h"

using namespace std;

class Patient {
private:
	int m_resistance;
	list<Virus*> m_VirusList;
	int m_state;

public:
	Patient();
	~Patient();

	void DoStart();
	void TakeMadicine();
	void ReduceResistance();
	void DoDie();
	int GetState();
};

#endif