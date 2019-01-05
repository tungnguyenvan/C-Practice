#ifndef __DENGUE_VIRUS_H__
#define __DENGUE_VIRUS_H__
#include "Virus.h"

class DengueVirus : virtual public Virus {
private:
	char m_protein[4];
public:
	DengueVirus();
	DengueVirus(const DengueVirus &dengueVirus);
	~DengueVirus();

	int GetResistance() override;
	void ReduceResistance(int medicine_resistance, list<Virus*> *listVirus) override;
	void DoBorn() override;
	void DoDie() override;
	void DoClone(list<Virus*> listVirus) override;
	void InitResistance() override;
};

#endif