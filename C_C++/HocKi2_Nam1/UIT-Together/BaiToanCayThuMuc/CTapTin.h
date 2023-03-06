#pragma once
#include"CLuuTru.h"
#include<iostream>
using namespace std;

class CTapTin:public CLuuTru
{
public:
	void Nhap();
	void Xuat();
	float TinhDungLuong();
	int DemTapTin();
	int DemThuMuc();
};

