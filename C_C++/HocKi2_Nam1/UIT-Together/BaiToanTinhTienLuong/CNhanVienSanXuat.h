#pragma once
#include"CNhanVien.h"
#include<iostream>
using namespace std;

class CNhanVienSanXuat:public CNhanVien
{
protected:
	int SoSanPham;
public:
	void Nhap();
	void TinhLuong();
	void Xuat();
	float LayLuong();
	CNhanVien* TimKiem(string);
};

