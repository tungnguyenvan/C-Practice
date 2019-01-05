#ifndef __FLU_VIRUS_H__
#define __FLU_VIRUS_H__
#include "Virus.h"
#include <vector>

using namespace std;

class FluVirus : virtual public Virus {
private :
	int m_color;

public:
	FluVirus();
	~FluVirus();

	void DoBorn() override;
	void DoDie() override;
	void DoClone() override;
	void InitResistance() override;
};

#endif // !__FLU_VIRUS_H__

