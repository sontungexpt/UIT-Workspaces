#pragma once
#include "CDiem.h"

class CDuongThang
{
	float a;
	float b;
	float c;
public:
	void KhoiTao();
	void KhoiTao(float, float, float);
	void KhoiTao(const CDuongThang&);
	CDuongThang();
	CDuongThang(float, float, float);
	CDuongThang(const CDuongThang&);
	void Nhap();
	friend istream& operator>>(istream&, CDuongThang&);
	void Xuat();
	friend ostream& operator<<(ostream&, CDuongThang&);
	float getA();
	float getB();
	float getC();
	CDuongThang& operator = (const CDuongThang&);
	void setA(float);
	void setB(float);
	void setC(float);
	
	int isTrung(const CDuongThang&);
	int isKhongTrung(const CDuongThang&);
	int ktSongSong(const CDuongThang&);
	int ktCatNhau(const CDuongThang&);
	int ktVuongGoc(const CDuongThang&);
	int operator<(const CDuongThang&);
	int operator>(const CDuongThang&);
	int operator<=(const CDuongThang&);
	int operator>=(const CDuongThang&);
	int operator==(const CDuongThang&);
	int operator!=(const CDuongThang&);
	float KhoangCachGoc() const;
	CDiem GiaoDiem(const CDuongThang&);
	~CDuongThang();

};