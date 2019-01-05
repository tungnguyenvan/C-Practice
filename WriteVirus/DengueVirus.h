#ifndef __DENGUE_VIRUS_H__
#define __DENGUE_VIRUS_H__
#include "Virus.h"

class DengueVirus : virtual Virus {
private:
	char m_protein[4];
public:
	DengueVirus();
	DengueVirus(const DengueVirus &dengueVirus);
	~DengueVirus();

	void DoBorn() override;
	void DoDie() override;
	void DoClone() override;
	void InitResistance() override;
};

#endif