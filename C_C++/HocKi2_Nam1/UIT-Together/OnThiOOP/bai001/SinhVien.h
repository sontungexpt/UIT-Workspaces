#pragma once
#include<iostream>
#include<string>
using namespace std;
class SinhVien
{
protected:
	string MaSoSinhVien;
	string HoTen;
	string DiaChi;
	int TongSoTinChi;
	float DiemTrungBinh;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual int DuDieuKienTotNghiep();
	virtual int LaDaiHoc();
	virtual float GetDiemTrungBinh();
};