#pragma once
#include "CNhanVien.h"

class CNhanVienSanXuat:public CNhanVien
{
protected:
	int SoSanPham;
public:
	void Nhap();
	void Xuat();
	void TinhLuong();
	long LayLuong();
	CNhanVien* TimKiem(string);
};

