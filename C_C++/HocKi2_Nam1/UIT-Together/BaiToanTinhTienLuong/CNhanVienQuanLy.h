#pragma once
#include"CNhanVien.h"
#include<iostream>
using namespace std;

class CNhanVienQuanLy :public CNhanVien
{
protected:
	float HeSoChucVu;
	float Thuong;
public:
	void Nhap();
	void TinhLuong();
	void Xuat();
	float LayLuong();
	CNhanVien* TimKiem(string);
};

