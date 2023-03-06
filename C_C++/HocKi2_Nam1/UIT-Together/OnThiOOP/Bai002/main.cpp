#pragma once

class CVeTungPhan : public CVe
{

};
class CCongVien
{
protected:
	int n;
	CVe* ds[100];
public:
	void Nhap();
	void Xuat();
	int TongTienVe();
	int DemVeTungPhan();
};


