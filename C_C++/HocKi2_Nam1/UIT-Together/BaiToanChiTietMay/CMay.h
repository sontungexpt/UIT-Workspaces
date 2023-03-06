#pragma once
#include"CChiTiet.h"
#include<iostream>
using namespace std;

class CMay
{
protected:
	int n;
	CChiTiet* ds[100];
public:
	void Nhap();
	void Xuat();
	float TinhTien();
	CChiTiet* TimKiem(long);
	int DemChiTietDon();
};
