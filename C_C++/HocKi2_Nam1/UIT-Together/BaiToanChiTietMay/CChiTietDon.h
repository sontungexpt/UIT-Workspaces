#pragma once
#include"CChiTiet.h"
#include<iostream>
using namespace std;

class CChiTietDon :public CChiTiet
{
protected:
	float giatien;
public:
	void Nhap();
	void Xuat();
	float TinhTien();
	CChiTiet* TimKiem(long);
	int DemChiTietDon();
};
