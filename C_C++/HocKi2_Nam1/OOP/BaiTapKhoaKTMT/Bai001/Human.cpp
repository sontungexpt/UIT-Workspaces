#include "Human.h"

#pragma region Constructor
Human::Human()
{
	this->amount = 0;
}
Human::Human(int amount)
{
	this->amount = amount;
}
#pragma endregion


#pragma region Method
void Human::Input()
{
	if (amount == 0)
	{
		cout << "Nhap so luong doi tuong: ";
		cin >> this->amount;
	}

	for (int i = 0; i < this->amount; i++)
	{
		int key = 0;
		do {
			cout << "Chon loai doi tuong: (1.Sinh vien, 2.Hoc sinh, 3.Cong nhan, 4.Nghe si, 5.Ca si): ";
			cin >> key;
		} while (key < 1 || key >5);
		switch (key)
		{
		case 1:
			job[i] = new CollegeStudent;
			break;
		case 2:
			job[i] = new Pupil;
			break;
		case 3:
			job[i] = new Worker;
			break;
		case 4:
			job[i] = new Artist;
			break;
		case 5:
			job[i] = new Singer;
			break;
		default:
			break;
		}
		job[i]->Input();
	}
}

void Human::Print()
{
	cout << "\n\nSo luong doi tuong: " << this->amount;
	for (int i = 0; i < this->amount; i++)
	{
		cout << "\n\nDoi tuong thu " << i;
		job[i]->Print();
	}
	cout << endl << endl;
}
#pragma endregion

