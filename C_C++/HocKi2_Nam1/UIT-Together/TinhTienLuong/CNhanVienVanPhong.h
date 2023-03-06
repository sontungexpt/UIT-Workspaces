#pragma once
#include "CNhanVien.h"

class CNhanVienVanPhong:public CNhanVien
{
protected:
	int SoNgayLamViec;
	long TroCap;
public:
	void Nhap();
	void Xuat();
	void TinhLuong();
	long LayLuong();
	CNhanVien* TimKiem(string);
};

