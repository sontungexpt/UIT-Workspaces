#include "SinhVienDaiHoc.h"

void SinhVienDaiHoc::Nhap()
{
	cout << "\nNhap ma so sinh vien: ";
	cin.ignore();
	getline(cin, MaSoSinhVien);
	cout << "\nNhap ho ten: ";
	getline(cin, HoTen);
	cout << "\nNhap dia chi: ";
	getline(cin, DiaChi);
	cout << "\nNhap tong so tin chi: ";
	cin >> TongSoTinChi;
	cout << "\nNhap DiemTrungBinh: ";
	cin >> DiemTrungBinh;
	cout << "\nNhap ten luan van: ";
	cin.ignore();
	getline(cin, TenLuanVan);
	cout << "\nNhap diem luan van: ";
	cin >> DiemLuanVan;
}
void SinhVienDaiHoc::Xuat()
{
	cout << "\nSinh vien dai hoc.";
	cout << "\nMa so sinh vien: " << MaSoSinhVien;
	cout << "\nHo ten: " << HoTen;
	cout << "\nDia chi: " << DiaChi;
	cout << "\nTong so tin chi: " << TongSoTinChi;
	cout << "\nDiem trung binh: " << DiemTrungBinh;
	cout << "\nTen luan van: " << TenLuanVan;
	cout << "\nDiem luan van: " << DiemLuanVan;
	cout << "\n\n";
}
int SinhVienDaiHoc::DuDieuKienTotNghiep()
{
	if (TongSoTinChi >= 170 && DiemTrungBinh >= 5 && DiemLuanVan >= 5)
		return 1;
	return 0;
}
int SinhVienDaiHoc::LaDaiHoc()
{
	return 1;
}
float SinhVienDaiHoc::GetDiemTrungBinh()
{
	return DiemTrungBinh;
}