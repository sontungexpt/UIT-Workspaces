//Họ và tên: Trần Võ Sơn Tùng
//Buổi 02 - Bài 01
//Làm đủ các câu 
//+ NÂNG CAO(1đ) : Câu 27, 29

#include <iostream>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include <cctype>

using namespace std;

#define MAX 10000

struct Node
{
	int info;
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
void Input(List&, int, int, int, int);
int CreateRandomValue(int, int);
void Print(List);
bool IsDivisibleBy2(int);
bool IsNotDivisibleBy2(int);
int GetSum(List, bool(*)(int));
int Compare(int, int);
void Reverse(List&);
void PrintMenu();
void Pause();

int main()
{
	List list;
	Init(list);

	char key = 0;
	while (key != 27)
	{
		system("cls");
		PrintMenu();
		key = _getch();
		switch (key)
		{
		case '1':
		{
			system("cls");
			Input(list);
			Pause();
			break;
		}
		case '2':
		{
			system("cls");
			Input(list, 39, 59, -99, 99);
			Pause();
			break;
		}
		case '3':
		{
			system("cls");
			if (IsEmpty(list))
			{
				cout << "Ban chua nhap danh sach!";
				Pause();
				break;
			}
			Print(list);
			Pause();
			break;
		}
		case '4':
		{
			system("cls");
			if (IsEmpty(list))
			{
				cout << "Ban chua nhap danh sach!";
				Pause();
				break;
			}
			int sumOfEven = GetSum(list, IsDivisibleBy2);
			int sumOfOdd = GetSum(list, IsNotDivisibleBy2);
			cout << "Tong cac so chan la: " << sumOfEven << endl;
			cout << "Tong cac so le la: " << sumOfOdd << endl;
			if (Compare(sumOfEven, sumOfOdd) == 1)
				cout << "chan < le\n";
			else if (Compare(sumOfEven, sumOfOdd) == 0)
				cout << "chan = le\n";
			else
				cout << "Chan > le\n";
			Pause();
			break;
		}
		case '5':
		{
			system("cls");
			if (IsEmpty(list))
			{
				cout << "Ban chua nhap danh sach!";
				Pause();
				break;
			}
			Reverse(list);
			Pause();
			break;
		}
		case 27:
		{
			system("cls");
			cout << "Ban Co Chac Muon Thoat Chuong Trinh?\n";
			cout << "Yes. Enter.\n";
			cout << "Back To Home. ESC.\n";
			cout << "Hay nhap lua chon cua ban.\n";
			int choice;
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
			break;
		}
	}
}

void PrintMenu()
{
	cout << "1. Nhap thu cong danh sach lien ket don\n\n";
	cout << "2. Nhap tu dong gia tri cho danh sach lien ket don\n\n";
	cout << "3. In danh sach lien ket don\n\n";
	cout << "4. Tinh tong cac so chan va so le, so sanh chan va le.(Cau 27)\n\n";
	cout << "5. Dao nguoc danh sach hien tai.(Cau 29)\n\n";
	cout << "ESC: Thoat chuong trinh\n\n";
	cout << "Hay nhap lua chon cua ban.\n\n";
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

Node* CreateNode(int x)
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
	Init(li);
	int n;
	cout << "Nhap so phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu thu " << i << ": ";
		int x;
		cin >> x;
		Node* newEle = CreateNode(x);
		if (newEle != nullptr)
			AddTail(li, newEle);
	}
}

void Input(List& li, int leftLimitOfN, int rightLimitOfN, int leftLimitOfValue, int rightLimitOfValue)
{
	Init(li);
	srand(time(NULL));
	int n = CreateRandomValue(leftLimitOfN, rightLimitOfN);
	for (int i = 0; i < n; i++)
	{
		int x = CreateRandomValue(leftLimitOfValue, rightLimitOfValue);
		AddTail(li, CreateNode(x));
	}
}

void Input(int arr[], int& n)
{
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu thu " << i << ": ";
		cin >> arr[i];
	}
}

int CreateRandomValue(int leftLimit, int rightLimit)
{
	int result = rand() % (rightLimit - leftLimit + 1) + leftLimit;
	return result;
}

void Print(List li)
{
	cout << "Cac phan tu trong danh sach la: ";
	for (Node* temp = li.pHead; temp != NULL; temp = temp->pNext)
	{
		cout << temp->info << setw(5);
	}
}

int GetSum(List li, bool(*comparisionFunct)(int))
{
	int sum = 0;
	for (Node* temp = li.pHead; temp != nullptr; temp = temp->pNext)
		if (comparisionFunct(temp->info) == true)
			sum += temp->info;
	return sum;
}

bool IsDivisibleBy2(int x)
{
	return (x % 2 == 0) ? true : false;
}

bool IsNotDivisibleBy2(int x)
{
	return (x % 2 != 0) ? true : false;
}

int Compare(int num1, int num2)
{
	if (num1 < num2)
		return 1;
	if (num1 == num2)
		return 0;
	if (num1 > num2)
		return -1;
}

void Reverse(List& li)
{
	Node* temp = nullptr;
	Node* current = nullptr;
	Node* next = nullptr;
	Node* prev = nullptr;

	temp = current = li.pHead;
	while (current != nullptr)
	{
		next = current->pNext;
		current->pNext = prev;
		prev = current;
		current = next;
	}
	li.pHead = prev;
	li.pTail = temp;
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

