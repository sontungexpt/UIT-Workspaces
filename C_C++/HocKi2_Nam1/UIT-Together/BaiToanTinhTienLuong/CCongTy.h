#pragma once
#include"CNhanVien.h"
#include<iostream>
using namespace std;

class CCongTy
{
protected:
	int n;
	CNhanVien* ds[100];
public:
	void Nhap();
	void Xuat();
	void TinhLuong();
	float TongLuong();
	CNhanVien* TimKiem(string);
};

