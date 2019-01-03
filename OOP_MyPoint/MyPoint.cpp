#include <iostream>
#include "MyPoint.h"
#include <math.h>

using namespace std;

MyPoint::MyPoint() {
	this->mPosX = 0;
	this->mPostY = 0;
}

MyPoint::MyPoint(int x, int y) {
	this->mPosX = x;
	this->mPostY = y;
}

void MyPoint::Display() {
	cout << "This is my point: " << mPosX << ":" << mPostY << endl;
}

void MyPoint::SetX(int x) {
	this->mPosX = x;
}

int MyPoint::GetX() {
	return this->mPosX;
}

void MyPoint::SetY(int y) {
	this->mPostY = y;
}

int MyPoint::GetY() {
	return this->mPostY;
}

float MyPoint::Distance(MyPoint p) {
	double distanceX = pow(p.GetX() - this->GetX(), 2);
	double distanceY = pow(p.GetY() - this->GetY(), 2);

	return sqrt(distanceX + distanceY);
}

MyPoint::~MyPoint() {

}