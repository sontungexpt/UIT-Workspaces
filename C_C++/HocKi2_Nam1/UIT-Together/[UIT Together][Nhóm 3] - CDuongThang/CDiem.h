#pragma once
#include <iostream>
using namespace std;

class CDiem
{
	float x;
	float y;
public:
	CDiem();
	CDiem(float, float);
	CDiem(const CDiem&);
	~CDiem();
	void Nhap();
	void Xuat();
	float getX() const;
	float getY() const;
	void setX(float);
	void setY(float);
	friend istream& operator>>(istream&, CDiem&);
	friend ostream& operator<<(ostream&, CDiem&);
	CDiem& operator=(const CDiem&);
	float KhoangCach() const;
	int operator>(const CDiem&);
	int operator<(const CDiem&);
	int operator>=(const CDiem&);
	int operator<=(const CDiem&);
	int operator==(const CDiem&);
	int operator!=(const CDiem&);
};

