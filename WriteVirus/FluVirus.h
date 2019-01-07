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
	FluVirus(const FluVirus &fluVirus);
	~FluVirus();

	bool ReduceResistance(int medicine_resistance) override;
	void DoBorn() override;
	void DoDie() override;
	FluVirus *DoClone() override;
	void InitResistance() override;
};

#endif // !__FLU_VIRUS_H__

