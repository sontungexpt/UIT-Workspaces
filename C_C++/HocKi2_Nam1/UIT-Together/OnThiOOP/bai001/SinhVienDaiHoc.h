#pragma once
#include "SinhVien.h"

class SinhVienDaiHoc: public SinhVien
{
protected:
	string TenLuanVan;
	float DiemLuanVan;
public:
	void Nhap();
	void Xuat();
	int DuDieuKienTotNghiep();
	int LaDaiHoc();
	float GetDiemTrungBinh();
};

