#pragma once
#include"CNgay.h"
#include<iostream>
using namespace std;

class CNhanVien
{
protected:
	string HoTen;
	CNgay NgaySinh;
	float Luong;
	float LuongCoBan;
public:
	virtual void Nhap();
	virtual void TinhLuong();
	virtual void Xuat();
	virtual float LayLuong();
	virtual CNhanVien* TimKiem(string);
};




