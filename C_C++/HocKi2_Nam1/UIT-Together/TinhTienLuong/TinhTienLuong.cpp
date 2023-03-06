#include "CCongTy.h"

int main()
{
	CCongTy a;
	cout << "Nhap du lieu cho cong ty a: \n";
	a.Nhap();

	a.TinhLuong();

	cout << "\nDu lieu cac nhan vien cua cong ty a: \n";
	a.Xuat();

	cout << "\nTong luong cua cong ty a la: " << a.TongLuong() << endl;

	string TenNV;
	cout << "\nNhap ten nhan vien can tim: ";
	getline(cin, TenNV);
	if (a.TimKiem(TenNV) != NULL)
		cout << "Tim thay!";
	else
		cout << "Khong tim thay!";

	return 1;
}