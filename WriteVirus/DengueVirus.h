#ifndef __DENGUE_VIRUS_H
#define __DENGUE_VIRUS_H
#include "Virus.h"

class DengueVirus : public Virus
{
private:
	char m_protein[4];
public:
	DengueVirus();
	~DengueVirus();

	void DoBorn() override;
	Virus * DoClone() override;
	void DoDie() override;
	void InitResistance() override;
};

#endif // !__DENGUE_VIRUS_H