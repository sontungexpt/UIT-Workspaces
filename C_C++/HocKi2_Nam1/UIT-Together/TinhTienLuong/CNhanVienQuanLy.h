#pragma once
#include "CNhanVien.h"

class CNhanVienQuanLy:public CNhanVien
{
protected:
	int HeSoChucVu;
	long Thuong;
public:
	void Nhap();
	void Xuat();
	void TinhLuong();
	long LayLuong();
	CNhanVien* TimKiem(string);
};

