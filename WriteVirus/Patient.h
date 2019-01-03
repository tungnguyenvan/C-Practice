#ifndef __PATIENT_H__
#define __PATIENT_H__
#include <list>
#include "Virus.h"

using namespace std;

class Patient
{
private:
	int m_resistance;
	list<Virus> m_virusList;
	int m_state;

public:
	Patient();
	~Patient();

	int InitResistance();
	void DoStart();
	void TakeMidicine();
	void ReduceResistance(int medicine_resistance);
};

#endif // !__PATIENT_H__