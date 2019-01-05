#include <iostream>
#include <list>
#include "Patient.h"

using namespace std;

int main() {
	Patient p;
	char t = 0;
	cout << "total virus: " << p.GetListVirus().size() << endl;
	while (p.GetState() == 1)
	{
		system("cls");
		cout << "Resistance: [Patient: " << p.GetResistance() << "]\t[Virus: " << p.GetTotalResistanceVirus() << "]" << endl << endl;
		printf("Take Medicine (0 = NO, 1 = YES): ");
		cin >> t; cout << endl;
		if (t == '1') {
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << medicine_resistance << endl;
			p.TakeMadicine(medicine_resistance);
		}
	}

	system("pause");
	return 0;
}