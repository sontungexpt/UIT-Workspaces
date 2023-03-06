#pragma once
#include"CNhanVien.h"
#include<iostream>
using namespace std;

class CNhanVienVanPhong: public CNhanVien
{
protected:
	int SoNgayLamViec;
	float TroCap;
public:
	void Nhap();
	void TinhLuong();
	void Xuat();
	float LayLuong();
	CNhanVien* TimKiem(string);
};

