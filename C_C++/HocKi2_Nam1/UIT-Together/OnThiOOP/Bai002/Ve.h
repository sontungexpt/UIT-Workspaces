#pragma once
#include<iostream>
#include<string>
using namespace std;
class Ve
{
protected:
	string MaSo;
	string HoTen;
	int NamSinh;
	int SoTroChoi;
	int GiaVe;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual long TinhTien();
	virtual int DemVeTungPhan();
};

