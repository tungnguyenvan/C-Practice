#ifndef __VIRUS_H__
#define __VIRUS_H__

class Virus {
private:
	char* m_dna;
	int m_resistance;

public:
	Virus();
	~Virus();
	Virus(const Virus &virus);

	void LoadADNInformation();
	void ReduceResistance(int medicine_resistance);

	virtual void DoBorn() = 0;
	virtual void DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};

#endif // !__VIRUS_H__