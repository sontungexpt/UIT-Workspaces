#pragma once
#include <iostream>
#include <string>
#include "CNgay.h"

using namespace std;

class CNhanVien
{
protected:
	string HoTen;
	CNgay NgaySinh;
	long Luong;
	long LuongCoBan;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual void TinhLuong();
	virtual long LayLuong();
	virtual CNhanVien* TimKiem(string);
};

