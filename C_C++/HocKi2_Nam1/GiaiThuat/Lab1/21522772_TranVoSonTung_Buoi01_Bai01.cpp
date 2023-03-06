//Họ và tên: Trần Võ Sơn Tùng
//Buổi 01 - Bài 01
//Ghi chú: Ý 1, ý 2 gộp vô một menu 1


#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
using namespace std;

#define MAX 100

struct Monomial //đơn thức
{
	int coefficient = 0;
	int indexNumber = 0;

	//constructor
	Monomial() {}
	Monomial(int coefficient, int indexNumber)
	{
		this->coefficient = coefficient;
		this->indexNumber = indexNumber;
	}
};
typedef struct Monomial Monomial;



//Begin fraction method
void InputPolyomial(Monomial monomial[MAX], int& n);
void AutoInputPolyomial(Monomial monomial[MAX], int& n);
void PrintPolyomial(Monomial monomial[MAX], int n);
void InputMonomial(Monomial& monomial);
void AutoInputMonomial(Monomial& monomial);
void PrintMonomial(Monomial monomial);
double CalcMonomial(Monomial monomial, int x);
double CalcPolyomial(Monomial monomial[MAX], int n);
void FormatPolyomial(Monomial monomial[MAX], int &n);
void FormatAndCreateNewPolyomial(Monomial monomial[], int n, Monomial newMonomial[], int& newN);
void RemoveAt(Monomial monomial[MAX], int &n, unsigned int index);
Monomial FindMonomialWithMaxIndexNumber(Monomial monomial[MAX], int n);
Monomial FindMonomialWithMinIndexNumber(Monomial monomial[MAX], int n);


//End fraction method
void Pause();
void PrintNotifications();

//begin decreasing sort
void SwapMonomial(Monomial& monomial1, Monomial& monomial2);
void DoDecreasingQuickSortForIndexNumber(Monomial arr[], int n, unsigned int left, unsigned int right);
int FindParticipationForIndexNumber(Monomial monomial[], int n, unsigned int left, unsigned int right);

//end decreasing sort



int main()
{
	Monomial monomial[MAX]{};
	int n;
	Monomial newMonomial[MAX]{};
	int newN;
	char key = 0;
	do
	{
	Menu:
		system("cls");
		cout << "\n1. Nhap Da Thuc(thu cong hoac tu dong). y = f(x).\n";
		cout << "2. Xuat Da Thuc y = f(x).\n";
		cout << "3. Tinh Da Thuc y = f(x).\n";
		cout << "4. Tim Don Thuc Co Bac Lon Nhat Trong Da Thuc.\n";
		cout << "5. Tim Don Thuc Co Bac Nho Nhat Trong Da Thuc.\n";
		cout << "6. Xap Xep Da Thuc Theo Bac Giam Gian.\n";
		cout << "ESC. Thoat Chuong Trinh.\n";
		PrintNotifications();

		char choice = 0;
		key = _getch();
		switch (key)
		{
			case '1':
			{
				system("cls");
				cout << "1. Nhap Da Thuc Thu Cong y = f(x).\n";
				cout << "2. Nhap Da Thuc Tu Dong y = f(x).\n";
				cout << "Vui Long Nhap Lua Chon Cua Ban!\n";
				do
				{
					choice = _getch();
					switch (choice)
					{
						case'1':
						{
							InputPolyomial(monomial, n);
							break;
						}
						case'2':
						{
							AutoInputPolyomial(monomial, n);
							break;
						}
						default: 
						{
							break;
						}
					}
				} while (choice != '1' && choice != '2');
				Pause();
				break;
			}
			case '2':
			{
				system("cls");
				if (monomial[0].coefficient == 0 && monomial[0].indexNumber == 0)
				{
					cout << "Ban Chua Nhap Da Thuc Nao! Vui Long Nhap Da Thuc\n";
					Pause();
					goto Menu;
				}
				else
				{
					cout << "1. Gop Cac Don Thuc Co Cung Bac Voi Nhau Va Xuat Da Thuc.\n";
					cout << "2. Xuat Da Thuc Goc Vua Nhap.\n";
					PrintNotifications();
					do
					{
						choice = _getch();
						switch (choice)
						{
							case '1':
							{
								FormatAndCreateNewPolyomial(monomial, n, newMonomial, newN);
								PrintPolyomial(newMonomial, newN);
								break;
							}
							case '2':
							{
								PrintPolyomial(monomial, n);
								break;
							}
							default:
							{
								break;
							}
						}
					} while (choice != '1' && choice != '2');
				}
				Pause();
				break;
			}
			case '3':
			{
				system("cls");
				if (monomial[0].coefficient == 0 && monomial[0].indexNumber == 0)
				{
					cout << "Ban Chua Nhap Da Thuc Nao! Vui Long Nhap Da Thuc\n";
					Pause();
					goto Menu;
				}
				else
				{
					cout << "\ny = f(x) = " << CalcPolyomial(monomial, n);
					Pause();
				}
				break;
			}
			case '4':
			{
				system("cls");
				if (monomial[0].coefficient == 0 && monomial[0].indexNumber == 0)
				{
					cout << "Ban Chua Nhap Da Thuc Nao! Vui Long Nhap Da Thuc\n";
					Pause();
					goto Menu;
				}
				else
				{	
				cout << "1. Gop Cac Da Thuc Co Cung Bac Lai Voi Nhau Va Tim Ra Don Thuc Dau Tien Co Bac Cao Nhat.\n";
				cout << "2. Giu Nguyen Da Thuc Va Tim Ra Don Thuc Dau Tien Co Bac Cao Nhat.\n";
				PrintNotifications();
				do
				{
					choice = _getch();
					switch (choice)
					{
						case '1':
						{
							FormatAndCreateNewPolyomial(monomial, n, newMonomial, newN);
							cout << "Don Thuc Co Bac Cao Nhat La: ";
							PrintMonomial(FindMonomialWithMaxIndexNumber(newMonomial, newN));
							break;
						}
						case '2':
						{
							cout << "Don Thuc Co Bac Cao Nhat La: ";
							PrintMonomial(FindMonomialWithMaxIndexNumber(monomial, n));
							break;
						}
						default:
						{
							break;
						}
					}
				} while (choice != '1' && choice != '2');
				Pause();
				}
				break;
			}
			case '5':
			{
				system("cls");
				if (monomial[0].coefficient == 0 && monomial[0].indexNumber == 0)
				{
					cout << "Ban Chua Nhap Da Thuc Nao! Vui Long Nhap Da Thuc\n";
					Pause();
					goto Menu;
				}
				else
				{
				cout << "1. Gop Cac Da Thuc Co Cung Bac Lai Voi Nhau Va Tim Ra Don Thuc Dau Tien Co Bac Thap Nhat.\n";
				cout << "2. Giu Nguyen Da Thuc Va Tim Ra Don Thuc Dau Tien Co Bac Thap Nhat.\n";
				PrintNotifications();
				do
				{
					choice = _getch();
					switch (choice)
					{
						case '1':
						{
							FormatAndCreateNewPolyomial(monomial, n, newMonomial, newN);
							cout << "Don Thuc Co Bac Thap Nhat La: ";
							PrintMonomial(FindMonomialWithMinIndexNumber(newMonomial, newN));
							break;
						}
						case '2':
						{
							cout << "Don Thuc Co Bac Thap Nhat La: ";
							PrintMonomial(FindMonomialWithMinIndexNumber(monomial, n));
							break;
						}
						default: 
						{
							break;
						}
					}
				} while (choice != '1' && choice != '2');
				Pause();
				}
				break;
			}
			case '6':
			{
				system("cls");
				if (monomial[0].coefficient == 0 && monomial[0].indexNumber == 0)
				{
					cout << "Ban Chua Nhap Da Thuc Nao! Vui Long Nhap Da Thuc\n";
					Pause();
					goto Menu;
				}
				else
				{
					cout << "1. Gop Cac Don Thuc Co Cung Bac Voi Nhau Va Sap Xep Da Thuc.\n";
					cout << "2. Sap Xep Da Thuc Goc Vua Nhap.\n";
					PrintNotifications();
					do
					{
						choice = _getch();
						switch (choice)
						{
						case '1':
						{
							FormatAndCreateNewPolyomial(monomial, n, newMonomial, newN);
							DoDecreasingQuickSortForIndexNumber(newMonomial, newN, 0, newN - 1);
							PrintPolyomial(newMonomial, newN);
							break;
						}
						case '2':
						{
							DoDecreasingQuickSortForIndexNumber(monomial, n, 0, n - 1);
							PrintPolyomial(monomial, n);
							break;
						}
						default:
						{
							break;
						}
						}
					} while (choice != '1' && choice != '2');
				}
				Pause();
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
				system("cls");
				break;
			}
		}
	}while (key != 27);
	return 0;
}
	

//Begin function
void InputPolyomial(Monomial monomial[MAX], int& n)
{
	do {
		cout << "\nNhap so don thuc: ";
		cin >> n;
		if (n > MAX)
			cout << "Toi da " << MAX - 1 << " don thuc! Vui long nhap lai.";
	} while (n > MAX);

	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap don thuc thu " << i + 1 <<": "<< endl;
		InputMonomial(monomial[i]);
	}
}

void AutoInputPolyomial(Monomial monomial[MAX], int& n)
{
	srand(time(NULL));
	n = rand() % (10 - 1 + 1) + 1;
	for (int i = 0; i < n; i++)
		AutoInputMonomial(monomial[i]);
}

void PrintPolyomial(Monomial monomial[MAX], int n)
{
	cout << " y = f(x) = ";
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			PrintMonomial(monomial[i]);
		else
		{
			if (monomial[i].coefficient >= 0)
			{
				cout << " + ";
			}
			else
			{
				cout << " - ";
				monomial[i].coefficient = abs(monomial[i].coefficient);
			}
			PrintMonomial(monomial[i]);
		}
	}
}

void AutoInputMonomial(Monomial& monomial)
{
	monomial.coefficient = rand() % (78 - 39 + 1) + 39;
	monomial.indexNumber = rand() % (9 - 0 + 1) + 1;
}

void InputMonomial(Monomial& monomial)
{
	cout << "Nhap he so: ";
	cin >> monomial.coefficient;
	cout << "Nhap so mu: ";
	cin >> monomial.indexNumber;
}

void PrintMonomial(Monomial monomial)
{
	cout << monomial.coefficient << "x^" << monomial.indexNumber;
}

double CalcMonomial(Monomial monomial , int x)
{
	return monomial.coefficient*pow(x,monomial.indexNumber);
}

double CalcPolyomial(Monomial monomial[MAX], int n)
{
	cout << "Tinh y = f(x)\n";
	cout << "Nhap x: ";
	double x = 0;
	cin >> x;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += CalcMonomial(monomial[i],x);
	}
	return sum;
}

Monomial FindMonomialWithMaxIndexNumber(Monomial monomial[MAX], int n)
{
	Monomial max;
	max.indexNumber = -100000000000;
	for (int i = 0; i < n; i++)
		if (max.indexNumber < monomial[i].indexNumber)
			max = monomial[i];
	return max;
}

Monomial FindMonomialWithMinIndexNumber(Monomial monomial[MAX], int n)
{
	Monomial min;
	min = monomial[0];
	for (int i = 0; i < n; i++)
		if (min.indexNumber > monomial[i].indexNumber)
			min = monomial[i];
	return min;
}

void RemoveAt(Monomial monomial[MAX], int &n, unsigned int index)
{
	for (int i = index; i < n - 1; i++)
	{
		monomial[i] = monomial[i + 1];
	}
	n--;
}

void FormatPolyomial(Monomial monomial[MAX], int &n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (monomial[i].indexNumber == monomial[j].indexNumber)
			{
				monomial[i].coefficient += monomial[j].coefficient;
				RemoveAt(monomial, n, j);
				j--;
			}	
		}
	}
}

void FormatAndCreateNewPolyomial(Monomial monomial[], int n, Monomial newMonomial[], int &newN)
{
	newN = n;
	for (int i = 0; i < newN; i++)
	{
		newMonomial[i].coefficient = monomial[i].coefficient;
		newMonomial[i].indexNumber = monomial[i].indexNumber;
	}
	FormatPolyomial(newMonomial, newN);
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


void SwapMonomial(Monomial &monomial1, Monomial &monomial2)
{
	Monomial temp = monomial1;
	monomial1 = monomial2;
	monomial2 = temp;
	/*temp.coefficient= monomial1.coefficient;
	temp.indexNumber = monomial1.indexNumber;
	monomial1.coefficient = monomial2.coefficient;
	monomial1.indexNumber = monomial1.indexNumber;
	monomial2.coefficient = temp.coefficient;
	monomial2.indexNumber = temp.indexNumber;*/
}

void DoDecreasingQuickSortForIndexNumber(Monomial arr[], int n, unsigned int left, unsigned int right)
{
	if (left < right)
	{	
		int par = FindParticipationForIndexNumber(arr, n, left, right);	
		DoDecreasingQuickSortForIndexNumber(arr, n,left, par);
		DoDecreasingQuickSortForIndexNumber(arr, n,par + 1, right);
	}
}

int FindParticipationForIndexNumber(Monomial monomial[],int n, unsigned int left, unsigned int right)
{
	int pivot = monomial[(left + right) / 2].indexNumber;
	int i = left-1;
	int j = right+1;
	while (i < j)
	{
		do
		{
			i++;
		} while (monomial[i].indexNumber > pivot);
		do
		{
			j--;
		} while (monomial[j].indexNumber < pivot);
		if (i < j)
		{
			swap(monomial[i],monomial[j]);
		}
	}
	return j;
}
