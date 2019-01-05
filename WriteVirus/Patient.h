#ifndef __PATIENT_H__
#define __PATIENT_H__
#include <list>
#include "Virus.h"
#include <list>

using namespace std;

class Patient {
private:
	int m_resistance;
	list<Virus*> m_VirusList;
	int m_state;

public:
	Patient();
	~Patient();
	list<Virus*> GetListVirus();
	void InitResistance();
	void DoStart();
	void TakeMadicine(int medicine_resistance);
	void ReduceResistance(int medicine_resistance);
	void DoDie();
	int GetState();
};

#endif