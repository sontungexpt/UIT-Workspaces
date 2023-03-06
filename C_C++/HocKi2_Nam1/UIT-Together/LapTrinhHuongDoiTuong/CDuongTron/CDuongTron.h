#pragma once
#include <iostream>

using namespace std;

class CDiem
{
private:
	float x;
	float y;
public:
	//Nhom phuong thuc khoi tao:
	CDiem();
	CDiem(float, float);
	CDiem(const CDiem&);
	void Nhap();
	friend istream& operator>>(istream&, CDiem&);

	//Nhom phuong thuc cung cap thong tin:
	friend ostream& operator<<(ostream&, CDiem&);
	void Xuat();
	float GetX();
	float GetY();

	//Nhom phuong thuc cap nhat thong tin:
	void SetX(float);
	void SetY(float);
	CDiem& operator=(const CDiem&);

	//Nhom phuong thuc kiem tra:
	int operator==(const CDiem&);

	//Nhom phuong thuc xu ly thong tin:
	float KhoangCach2Diem(const CDiem&);
	~CDiem();

};

class CDuongTron
{
private:
	CDiem I;
	float R;
public:
	//Nhom phuong thuc khoi tao:
	void KhoiTao();
	void KhoiTao(CDiem, float);
	void KhoiTao(const CDuongTron&);
	CDuongTron();
	CDuongTron(CDiem, float);
	CDuongTron(const CDuongTron&);
	void Nhap();
	friend istream& operator>>(istream&, CDuongTron&);

	//Nhom phuong thuc cung cap thong tin:
	void Xuat();
	friend ostream& operator<<(ostream&, CDuongTron&);
	CDiem GetI();
	float GetR();

	//Nhom phuong thuc cap nhat thong tin:
	CDuongTron& operator=(const CDuongTron&);
	void SetI(CDiem);
	void SetR(float);

	//Nhom phuong thuc kiem tra:
	int isDuongTron();
	int isCatHaiDiemPhanBiet(const CDuongTron&);
	int isLongNhau(const CDuongTron&);
	int isTiepXucTrong(const CDuongTron&);
	int isBanKinhBang(const CDuongTron&);
	int isONgoaiNhau(const CDuongTron&);
	int isTrung(const CDuongTron&);
	int operator==(CDuongTron);
	int operator!=(CDuongTron);
	int operator>=(CDuongTron);
	int operator<=(CDuongTron);
	int operator>(CDuongTron);
	int operator<(CDuongTron);

	//Nhom phuong thuc xu ly:
	float ChuVi();
	float DienTich();
	float KhoangCach2Tam(const CDuongTron&);
	float KhoangCachTamToiGoc();
	~CDuongTron();

};

