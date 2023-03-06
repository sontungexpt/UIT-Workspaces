#include"CCongTy.h"

int main()
{
	CCongTy X;
	X.Nhap();
	cout << "\nDanh sach nhan vien cua cong ty: \n";
	X.TinhLuong();
	X.Xuat();

	cout << "\nTong luong cua cong ty la: " << X.TongLuong();

	string str;
	cout << "\nNhap ho ten nhan vien can tim: ";
	cin >> str;
	CNhanVien* kq= X.TimKiem(str);
	cout << "\nNhan vien can tim: \n";
	kq->Xuat();
	return 0;
}