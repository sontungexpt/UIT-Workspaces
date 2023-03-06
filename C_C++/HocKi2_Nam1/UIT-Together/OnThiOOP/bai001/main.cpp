#pragma once
#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"
#include "Truong.h"

int main()
{
	Truong UIT;
	UIT.Nhap();
	UIT.Xuat();
	int dem = UIT.DemTotNghiep();
	cout << "\n\nSo sinh vien du dieu kien tot nghiep la: " << dem << endl;
	SinhVien* max = UIT.DiemTrungBinhLonNhat();
	if (max == NULL)
		cout << "\nKhong co sinh vien dai hoc.";
	else
	{
		cout << "\n\nSinh vien dai hoc co DiemTrungBinh lon nhat la: ";
		max->Xuat();
	}
	return 1;
}