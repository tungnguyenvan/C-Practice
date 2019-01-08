#ifndef __DENGUE_VIRUS_H__
#define __DENGUE_VIRUS_H__
#include "Virus.h"

class DengueVirus : virtual public Virus {
private:
	char *m_protein;
public:
	DengueVirus();
	DengueVirus(const DengueVirus *dengueVirus);
	~DengueVirus();

	bool ReduceResistance(int medicine_resistance) override;
	void DoBorn() override;
	void DoDie() override;
	DengueVirus *DoClone() override;
	void InitResistance() override;
};

#endif