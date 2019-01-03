#ifndef __MYPOINT_H__
#define __MYPOINT_H__

class MyPoint {
private:
	int mPosX;
	int mPostY;

public:
	MyPoint();
	MyPoint(int x, int y);
	void Display();
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
	MyPoint Distance(MyPoint p);
	~MyPoint();
};

#endif // __MYPOINT_H__
