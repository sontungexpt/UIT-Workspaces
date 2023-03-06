#include"CMachDien.h"
#include"CMachNoiTiep.h"
#include"CMachSongSong.h"
#include"CDienTro.h"

int main()
{
	CMachDien* a = NULL;
	int loai;
	cout << "Nhap loai (0. NT, 1. SS, 2. R): ";
	cin >> loai;
	switch (loai)
	{
	case 0: a = new CMachNoiTiep;
		break;
	case 1: a = new CMachSongSong;
		break;
	case 2: a = new CDienTro;
		break;
	}
	a->Nhap();
	cout << "Mach dien ban dau: ";
	a->Xuat();
	float kq = a->TinhDienTro();
	cout << "\nTong dien tro mach dien la: ";
	cout << kq;
	return 0;
}