#pragma once
#include"CNgay.h"
#include<iostream>
using namespace std;

class CLuuTru
{
protected:
	string Ten;
	CNgay NgayLap;
	float DungLuong;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual float TinhDungLuong();
	virtual int DemTapTin();
	virtual int DemThuMuc();
};

