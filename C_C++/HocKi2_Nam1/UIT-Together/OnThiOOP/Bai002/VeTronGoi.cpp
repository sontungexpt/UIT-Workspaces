#include "VeTronGoi.h"
void VeTronGoi::Nhap()
{
	Ve::Nhap();
	SoTroChoi = 30;
	GiaTien = 200000;
}
void VeTronGoi::Xuat()
{
	Ve::Xuat();
	cout << "\n Gia tien: " << GiaTien << "VND";
	cout << "\n So tro choi: " << SoTroChoi;
}
int VeTronGoi::TinhTien()
{
	return GiaTien;
}
int VeTronGoi::KtVeTungPhan()
{
	return 0;
}