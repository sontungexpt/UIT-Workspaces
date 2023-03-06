#pragma once
#include<iostream>
using namespace std;

class CChiTiet
{
protected:
	long maso;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual float TinhTien();
	virtual CChiTiet* TimKiem(long);
	virtual int DemChiTietDon();
};

