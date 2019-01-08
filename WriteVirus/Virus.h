#ifndef __VIRUS_H__
#define __VIRUS_H__
#include <list>

using namespace std;

class Virus {
private:
	char* m_dna;
	int m_resistance;

public:
	Virus();
	Virus(const Virus &virus);

	void LoadADNInformation();
	int GetResistance();
	void SetResistance(int m_resistance);

	virtual ~Virus();
	virtual bool ReduceResistance(int medicine_resistance) = 0;
	virtual void DoBorn() = 0;
	virtual Virus *DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};

#endif // !__VIRUS_H__