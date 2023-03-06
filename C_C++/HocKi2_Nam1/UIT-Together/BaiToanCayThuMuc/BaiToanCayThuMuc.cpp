#include"CDia.h"

int main()
{
	CDia X;
	X.Nhap();
	cout << "\nCac doi tuong thanh phan luu tru trong o dia la: \n";
	X.Xuat();
	cout << "\nTong dung luong cua o dia: " << X.TinhDungLuong();
	cout << "\nSo tap tin co trong o dia: " << X.DemTapTin();
	cout << "\nSo thu muc co trong o dia: " << X.DemThuMuc();
	return 0;
}