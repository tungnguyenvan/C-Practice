#include "vld.h"
#include <iostream>
#include <list>
#include "Patient.h"

#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	Patient *p = new Patient();
	char t = 0;
	while (p->GetState() == 1)
	{
		srand(NULL);
		//system("cls");
		if (p->GetListVirus().size() > 0) {
			cout << "\n\ntotal virus: " << p->GetListVirus().size() << endl;
			cout << "Resistance: [Patient: " << p->GetResistance() << "]\t[Virus: " << p->GetTotalResistanceVirus() << "]" << endl << endl;
			printf("Take Medicine (0 = NO, 1 = YES): ");
			cin >> t; cout << endl;
			if (t == '1') {
				int min = 1;
				int max = 7;
				int medicine_resistance = min + (rand() % (int)(max - min + 1));
				p->TakeMadicine(medicine_resistance);
			}
			else if (t == '0') {
				p->TakeMadicine(0);
			}
		}
		else {
			cout << "Patient Alive..." << endl;
			break;
		}
	}

	delete p;
	system("pause");
	return 0;
}