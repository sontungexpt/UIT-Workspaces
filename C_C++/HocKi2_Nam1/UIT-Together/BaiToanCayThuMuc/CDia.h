#pragma once
#include"CLuuTru.h"
#include<iostream>
using namespace std;
class CDia
{
protected:
	int n;
	CLuuTru* ds[100];
public:
	void Nhap();
	void Xuat();
	float TinhDungLuong();
	int DemTapTin();
	int DemThuMuc();
};

