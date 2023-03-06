#pragma once
#include "SinhVien.h"
class SinhVienCaoDang:public SinhVien
{
protected:
	float DiemThiTotNghiep;
public:
	void Nhap();
	void Xuat();
	int DuDieuKienTotNghiep();
	int LaDaiHoc();
	float GetDiemTrungBinh();
};

