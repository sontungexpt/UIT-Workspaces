#include "SinhVienCaoDang.h"

void SinhVienCaoDang::Nhap()
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
	cout << "\nNhap diem thi tot nghiep: ";
	cin >> DiemThiTotNghiep;
}
void SinhVienCaoDang::Xuat()
{
	cout << "\nSinh vien cao dang.";
	cout << "\nMa so sinh vien: " << MaSoSinhVien;
	cout << "\nHo ten: " << HoTen;
	cout << "\nDia chi: " << DiaChi;
	cout << "\nTong so tin chi: " << TongSoTinChi;
	cout << "\nDiem trung binh: " << DiemTrungBinh;
	cout << "\nDiem thi tot nghiep: " << DiemThiTotNghiep;
	cout << "\n\n";
}
int SinhVienCaoDang::DuDieuKienTotNghiep()
{
	if (TongSoTinChi >= 120 && DiemTrungBinh >= 5 && DiemThiTotNghiep >= 5)
		return 1;
	return 0;
}
int SinhVienCaoDang::LaDaiHoc()
{
	return 0;
}
float SinhVienCaoDang::GetDiemTrungBinh()
{
	return DiemTrungBinh;
}
