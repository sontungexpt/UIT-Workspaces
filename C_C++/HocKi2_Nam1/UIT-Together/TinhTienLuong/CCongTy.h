#pragma once
#include "CNhanVien.h"


class CCongTy
{
protected:
	int n;
	CNhanVien* ds[100];
public:
	void Nhap();
	void Xuat();
	void TinhLuong();
	long TongLuong();
	CNhanVien* TimKiem(string);
};

