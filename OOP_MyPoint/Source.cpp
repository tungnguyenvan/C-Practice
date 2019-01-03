#include <iostream>
#include "MyPoint.h"

using namespace std;

int main() {

	MyPoint firstPoint(12, 5);
	MyPoint secondPont(2, 1);

	cout << "this is position distance between current 2 point" << endl;
	cout << "This distance between 2 point: " << secondPont.Distance(firstPoint) << endl;

	system("pause");
	return 0;
}