//Họ và tên: Trần Võ Sơn Tùng
//Buổi 01 - Bài 02
//Ghi chú: Ý 1, ý 2 gộp vô một menu 1

#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

#define MAX 100

struct SequenceOfNumbers 
{
	int a[MAX]{};
	int n = 0;

	//constructor
	SequenceOfNumbers(){}
	SequenceOfNumbers(int a[], int n)
	{
		this->n = n;
	}
};
typedef struct SequenceOfNumbers SequenceOfNumbers;


//begin declare method
void InputSequenceOfNumbers(SequenceOfNumbers &a);
void AutoInputSequenceOfNumbers(SequenceOfNumbers &a);
void PrintSequenceOfNumbers(SequenceOfNumbers &a);
void MakeStatisticTable(SequenceOfNumbers& a);
void Pause();
void PrintNotifications();
//end declare method

int main()
{

	SequenceOfNumbers numberSequence;
	char key;
	char choice;
	do 
	{
	Menu:
		system("cls");
		cout << "1. Nhap gia tri cho day so(thu cong hoac tu dong).\n";
		cout << "2. Xuat day so vua nhap\n";
		cout << "3. Thong ke so luong cac phan tu co trong day.\n";
		cout << "ESC: Thoat Chuong Trinh.\n";
		PrintNotifications();
		key = _getch();
		
		switch (key)
		{
			case '1':
			{
				system("cls");
				cout << "1. Nhap gia tri cho day so thu cong.\n";
				cout << "2. Nhap gia tri cho day so tu dong.\n";
				PrintNotifications();
				do
				{
					choice = _getch();
					switch (choice)
					{
					case '1':
					{
						InputSequenceOfNumbers(numberSequence);
						Pause();
						break;
					}
					case '2':
					{
						AutoInputSequenceOfNumbers(numberSequence);
						Pause();
						break;
					}
					default:
					{
						break;
					}
					}

				} while (choice != '1' && choice != '2');
				break;
			}
			case '2':
			{
				system("cls");
				if (numberSequence.n == 0)
				{
					cout << "Ban Chua Nhap Day So!";
					Pause();
					goto Menu;
				}
				else
				{
					PrintSequenceOfNumbers(numberSequence);
					Pause();
				}
				break;
			}
			case '3':
			{
				system("cls");
				if (numberSequence.n == 0)
				{
					cout << "Ban Chua Nhap Day So!";
					Pause();
					goto Menu;
				}
				else
				{
					MakeStatisticTable(numberSequence);
					Pause();
				}
				break;
			}
			case 27:
			{
				system("cls");
				cout << "Ban Co Chac Muon Thoat Chuong Trinh?\n";
				cout << "Yes. Enter.\n";
				cout << "Back To Home. ESC.\n";
				PrintNotifications();
				do
				{
					choice = _getch();
					switch (choice)
					{
						case 13:
						{
							exit(0);
							break;
						}
						case 27:
						{
							key = 0;
							break;
						}
						default:
						{
							break;
						}
					}
				} while (choice != 13 && choice != 27);
				break;
			}
			default: 	
			{
				break;
			}
		}
	}while (key != 27);
}


//begin method
void InputSequenceOfNumbers(SequenceOfNumbers &a)
{
	do 
	{
		cout << "Nhap so chu so trong day: ";
		cin >> a.n;
	} while (a.n <= 0 || a.n > MAX);

	for (int i = 0; i < a.n; i++)
	{
		cout << "Nhap so thu " << i + 1<<": ";
		cin >> a.a[i];
	}
}

void AutoInputSequenceOfNumbers(SequenceOfNumbers &a)
{
	srand(time(NULL));
	a.n = rand()%(50-10+1) +10;
	for (int i = 0; i < a.n; i++)
	{
		a.a[i] = rand() % (999 - (-999) + 1) + (-999);
	}
}

void PrintSequenceOfNumbers(SequenceOfNumbers &a)
{
	cout << "Day so la: ";
	for (int i = 0; i < a.n; i++)
	{
		cout << a.a[i]<<" ";
	}
}

void MakeStatisticTable(SequenceOfNumbers& a)
{
	cout << endl;
	bool* existedNumber = new bool[a.n]();
	unsigned int count;
	for (int i = 0; i < a.n; i++)
	{
		if (existedNumber[i] == 1)
			continue;
		count = 1;
		for (int j = i + 1; j < a.n; j++)
		{
			if (a.a[i] == a.a[j])
			{
				count++;
				existedNumber[j] = 1;
			}
		}
		cout << a.a[i]<<": "<<count<<" lan\n";
	}
}

void Pause()
{
	cout << "\nNhan Enter De Tiep Tuc Chuong Trinh!\n";
	char enter;
	do
	{
		enter = _getch();
	} while (enter != 13);

}

void PrintNotifications()
{
	cout << "\nVui Long Nhap Lua Chon Cua Ban!\n";
}

//end method