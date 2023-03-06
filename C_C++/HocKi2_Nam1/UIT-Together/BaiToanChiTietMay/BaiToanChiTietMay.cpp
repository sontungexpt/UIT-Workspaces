#include"CMay.h"

int main()
{
	CMay X;
	X.Nhap();
	cout << "\nCac chi tiet cua may la: \n";
	X.Xuat();
	cout << "\nTri gia cua may: ";
	cout << X.TinhTien();
	long a;
	cout << "\nNhap ma so cua chi tiet can tim: ";
	cin >> a;
	cout << "\nChi tiet can tim: ";
	CChiTiet* kq = X.TimKiem(a);
	kq->Xuat();
	cout << "\nSo luong chi tiet don cua may: ";
	cout << X.DemChiTietDon();
}