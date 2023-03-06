#pragma once
#include "SinhVien.h"
class Truong
{
protected:
	SinhVien* ds[1000];
	int n;
public:
	void Nhap();
	void Xuat();
	int DemTotNghiep();
	SinhVien* DiemTrungBinhLonNhat();
};

