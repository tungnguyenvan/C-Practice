#ifndef __FLU_VIRUS_H__
#define __FLU_VIRUS_H__

#include "Virus.h"

class FluVirus : public Virus {
private:
	int color;

public:
	FluVirus();
	~FluVirus();

	void DoBorn() override;
	Virus * DoClone() override;
	void DoDie() override;
	void InitResistance() override;
};


#endif // !__FLU_VIRUS_H__
