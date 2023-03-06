#include "VeTungPhan.h"
void VeTungPhan::Nhap()
{
	Ve::Nhap();
	GiaTien = 70000;
	cout << "\n Nhap so tro choi: ";
	cin >> SoTroChoi;
}
void VeTungPhan::Xuat()
{
	Ve::Xuat();
	cout << "\n Gia tien: " << GiaTien;
	cout << "\n So tro choi: " << SoTroChoi;

}
int VeTungPhan::TinhTien()
{
	return GiaTien;
}
int VeTungPhan::ktVeTungPhan()
{
	return 1;
}