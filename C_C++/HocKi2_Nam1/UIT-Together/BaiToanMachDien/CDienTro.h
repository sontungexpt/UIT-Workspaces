#pragma once
#include<iostream>
#include"CMachDien.h"
using namespace std;

class CDienTro:public CMachDien
{
protected:
	string MaSo;
	float R;
public:
	void Nhap();
	void Xuat();
	float TinhDienTro();
};

