#include "Truong.h"

void Truong::Nhap()
{
	cout << "\nNhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int Loai;
		cout << "\nNhap 0 de nhap sinh vien Cao Dang.";
		cout << "\nNhap 1 de nhap sinh vien Dai Hoc.";
		cout << "\nBan muon nhap sinh vien CaoDang hay DaiHoc: ";
		cin >> Loai;
		switch (Loai)
		{
		case 0:
			ds[i] = new CSinhVienCaoDang;
			break;
		case 1:
			ds[i] = new CSinhVienDaiHoc;
			break;
		}
		ds[i]->Nhap();
	}
}
void Truong::Xuat()
{
	for (int i = 0; i < n; i++)
		ds[i]->Xuat();
}
int Truong::DemTotNghiep()
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (ds[i]->DuDieuKienTotNghiep() == 1)
			dem++;
	return dem;
}
CSinhVien* Truong::DiemTrungBinhLonNhat()
{
	float lc = -1;
	CSinhVien* temp = new CSinhVienDaiHoc;
	for (int i = 0; i < n; i++)
	{
		if (ds[i]->LaDaiHoc() == 1 && ds[i]->GetDiemTrungBinh() > lc)
		{
			lc = ds[i]->GetDiemTrungBinh();
			temp = ds[i];
		}
	}
	if (lc != -1)
		return temp;
	return NULL;
}