//Họ và tên: Trần Võ Sơn Tùng
//Buổi 02 - Bài 02
//Làm đủ các câu 

#include <iostream>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include <cctype>

using namespace std;

#define MAX 10000

struct Monomial //đơn thức
{
	int coefficient;
	int indexNumber;
	//constructor
	Monomial(int coefficient = 0, int indexNumber = 0)
	{
		this->coefficient = coefficient;
		this->indexNumber = indexNumber;
	}
};
typedef struct Monomial Monomial;

struct Node
{
	Monomial info;
	struct Node* pNext;
};
typedef struct Node Node;

struct List
{
	Node* pHead;
	Node* pTail;
};
typedef struct List List;


void Init(List&);
bool IsEmpty(List);
Node* CreateNode(int);
void AddHead(List&, Node*);
void AddTail(List&, Node*);
void Input(List&);
void Input(List&, int, int, int, int, int, int);
void Input(Monomial&);
void Input(Monomial&, int, int, int, int);
void Print(Monomial);
void Print(List);
int CreateRandomValue(int, int);
void Pause();
void PrintMenu();

int main()
{
	List list;
	Init(list);
	char key = 0;
	do
	{
		system("cls");
		PrintMenu();
		char choice = 0;
		key = _getch();
		switch (key)
		{
		case '1':
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
					system("cls");
					Input(list);
					Pause();
					break;

				case'2':
					system("cls");
					Input(list, 1, 10, 39, 79, 0, 9);
					Pause();
					break;

				default:
					break;
				}
			} while (choice != '1' && choice != '2');
			break;

		case '2':
			system("cls");
			if (IsEmpty(list))
			{
				cout << "Ban chua nhap danh sach da thuc!";
				Pause();
				break;
			}
			Print(list);
			Pause();
			break;

		case 27:
			system("cls");
			cout << "Ban Co Chac Muon Thoat Chuong Trinh?\n";
			cout << "Yes. Enter.\n";
			cout << "Back To Home. ESC.\n";
			cout << "Vui Long Nhap Lua Chon Cua Ban!\n";
			do
			{
				choice = _getch();
				switch (choice)
				{
				case 13:
					exit(0);
					break;

				case 27:
					key = 0;
					break;

				default:
					break;
				}
			} while (choice != 13 && choice != 27);
			break;

		default:
			break;

		}
	} while (key != 27);
	return 0;
}

//Begin function
void PrintMenu()
{
	cout << "1. Nhap Da Thuc(thu cong hoac tu dong). y = f(x).\n\n";
	cout << "2. Xuat Da Thuc y = f(x).\n\n";
	cout << "ESC. Thoat Chuong Trinh.\n\n";
	cout << "Vui Long Nhap Lua Chon Cua Ban.\n\n";
}

void Init(List& li)
{
	li.pHead = nullptr;
	li.pTail = nullptr;
}

bool IsEmpty(List li)
{
	if (li.pHead == nullptr)
		return 1;
	return 0;
}

Node* CreateNode(Monomial x)
{
	Node* newEle = new Node;
	if (newEle == nullptr)
		return nullptr;
	newEle->info = x;
	newEle->pNext = nullptr;
	return newEle;
}

void AddHead(List& li, Node* newEle)
{
	if (IsEmpty(li))
		li.pHead = li.pTail = newEle;
	else
	{
		newEle->pNext = li.pHead;
		li.pHead = newEle;
	}

}

void AddTail(List& li, Node* newEle)
{
	if (IsEmpty(li))
		li.pHead = li.pTail = newEle;
	else
	{
		li.pTail->pNext = newEle;
		li.pTail = newEle;
	}
}

void Input(List& li)
{
	int n;
	Init(li);
	do {
		cout << "Nhap so don thuc: ";
		cin >> n;
		if (n > MAX)
			cout << "Toi da " << MAX - 1 << " don thuc! Vui long nhap lai.\n";
		else if (n < 0)
			cout << "So don thuc khong duoc nho hon 0!Vui long nhap lai.\n";
	} while (n > MAX || n < 0);

	for (int i = 0; i < n; i++)
	{
		cout << "\nPhan tu thu " << i << ":";
		Monomial x;
		Input(x);
		Node* newEle = CreateNode(x);
		if (newEle != nullptr)
			AddTail(li, newEle);
	}
}

void Input(List& li, int leftLimitOfN, int rightLimitOfN, int leftLimOfCoefficient, int rightLimOfCoefficient, int leftLimOfIndexNumber, int rightLimOfIndexNumber)
{
	Init(li);
	srand(time(NULL));
	int n = CreateRandomValue(leftLimitOfN, rightLimitOfN);
	for (int i = 0; i < n; i++)
	{
		Monomial x;
		Input(x, leftLimOfCoefficient, rightLimOfCoefficient, leftLimOfIndexNumber, rightLimOfIndexNumber);
		AddTail(li, CreateNode(x));
	}
}

void Input(Monomial& monomial, int leftLimOfCoefficient, int rightLimOfCoefficient, int leftLimOfIndexNumber, int rightLimOfIndexNumber)
{
	monomial.coefficient = CreateRandomValue(leftLimOfCoefficient, rightLimOfCoefficient);
	monomial.indexNumber = CreateRandomValue(leftLimOfIndexNumber, rightLimOfIndexNumber);
}

void Input(Monomial& monomial)
{
	cout << "\nNhap he so: ";
	cin >> monomial.coefficient;
	cout << "Nhap so mu: ";
	cin >> monomial.indexNumber;
}

void Print(Monomial monomial)
{
	cout << monomial.coefficient << "x^" << monomial.indexNumber;
}

void Print(List li)
{
	cout << "Cac phan tu trong danh sach la: ";
	for (Node* temp = li.pHead; temp != NULL; temp = temp->pNext)
	{
		if (temp == li.pHead)
			Print(temp->info);
		else
		{
			if (temp->info.coefficient >= 0)
			{
				cout << " + ";
				Print(temp->info);
			}
			else
			{
				cout << " - ";
				Monomial monoTemp(temp->info.coefficient, temp->info.indexNumber);
				monoTemp.coefficient = abs(monoTemp.coefficient);
				Print(monoTemp);
			}
		}
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

int CreateRandomValue(int leftLimit, int rightLimit)
{
	int result = rand() % (rightLimit - leftLimit + 1) + leftLimit;
	return result;
}