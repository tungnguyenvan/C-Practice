#include <iostream>
#include "MyPoint.h"

using namespace std;

int main() {

	MyPoint firstPoint(12, 5);
	MyPoint secondPont(2, 1);

	MyPoint distancePoint = firstPoint.Distance(secondPont);

	cout << "this is position distance between current 2 point" << endl;
	cout << "x: " << distancePoint.GetX() << "  |  y: " << distancePoint.GetY() << endl;

	system("pause");
	return 0;
}