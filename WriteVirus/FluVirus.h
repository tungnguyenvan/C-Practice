#ifndef __FLU_VIRUS_H__
#define __FLU_VIRUS_H__
#include "Virus.h"
#include <list>

using namespace std;

class FluVirus : virtual public Virus {
private :
	int m_color;

public:
	FluVirus();
	~FluVirus();

	int GetResistance() override;
	void ReduceResistance(int medicine_resistance, list<Virus*> *listVirus) override;
	void DoBorn() override;
	void DoDie() override;
	void DoClone(list<Virus*> listVirus) override;
	void InitResistance() override;
};

#endif // !__FLU_VIRUS_H__

