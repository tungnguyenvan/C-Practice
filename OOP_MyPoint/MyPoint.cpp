#include <iostream>
#include "MyPoint.h"

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

MyPoint MyPoint::Distance(MyPoint p) {
	MyPoint point;

	point.mPosX = (this->mPosX + p.mPosX) / 2;
	point.mPostY = (this->mPostY + p.mPostY) / 2;

	return point;
}

MyPoint::~MyPoint() {

}