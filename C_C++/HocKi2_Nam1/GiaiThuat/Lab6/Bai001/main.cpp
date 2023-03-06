#include <iostream>
#include <string>

using namespace std;

struct BaiHat
{
	char name[100];
	char singerName[100];
	int time;

	BaiHat()
	{
		time = 0;
	}
};

struct Node
{
	BaiHat baiHat;
	struct Node* pNext;
};
typedef struct Node Node;

struct List
{
	Node* pHead;
	Node* pTail;
};
typedef struct List List;

struct Time
{
	int minute;
	int second;
};
typedef struct Time Time;



void Init(List&);
bool IsEmpty(List l);
Node* CreateNode(BaiHat);
void AddHead(List& l, Node*);
void AddTail(List& l, Node*);
void ThemBaiHat(List&);
void Print(List);
Time SumOfTimes(List l);
void Search(List l);
void Print(BaiHat);

int main()
{




	List list;
	Init(list);
	int key = -1;
	do
	{
		cout << "\n1. Them bai hat vao danh sach: ";
		cout << "\n2. Hien thi danh sach va so thu tu trong bai hat: ";
		cout << "\n3. Chuyen ve tong thoi luong phat theo phut:giay";
		cout << "\n4. Hien thi thong tin bai hat can tim kiem";
		cout << "\n0. Ket thuc chuong trinh";


		cout << "\nNhap lua chon cua ban: ";
		cin >> key;
		switch (key)
		{
		case 1:
			ThemBaiHat(list);
			break;
		case 2:
			Print(list);
			break;

		case 3:
			Time sum = SumOfTimes(list);
			cout << "Tong thoi luong phat la: " << sum.minute << ":" << sum.second;
			break;
		case 4:
			Search(list);
			break;
		case 0:
			exit(0);
		default:
			cout << "Nhap sai: ";
			break;
		}
		cout << endl;

		system("pause");
		system("cls");
	} while (key != 0);


}

void Init(List& l)
{
	l.pHead = l.pTail = nullptr;
}

bool IsEmpty(List l)
{
	return l.pHead == nullptr;
}

Node* CreateNode(BaiHat bh)
{
	Node* p = new Node;
	if (p == nullptr)
		return nullptr;
	p->baiHat = bh;
	p->pNext = nullptr;
	return p;
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


void AddTail(List& l, Node* p)
{
	if (IsEmpty(l))
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void ThemBaiHat(List& l)
{
	BaiHat a;
	cout << "\nNhap thong tin cua bai hat: ";
	cin.ignore();
	cout << "\nNhap ten bai hat: ";
	cin.getline(a.name, 100);
	cout << "\nNhap ten ca si: ";
	//cin.ignore();
	cin.getline(a.singerName, 100);
	cout << "\nNhap thoi gian phat: ";
	cin >> a.time;
	AddHead(l, CreateNode(a));
}

void Print(List l)
{
	int key = 1;
	for (Node* temp = l.pHead; temp != nullptr; temp = temp->pNext)
	{
		cout << endl << key++ << ". ";
		Print(temp->baiHat);
	}
}

Time SumOfTimes(List l)
{
	int sum = 0;
	for (Node* temp = l.pHead; temp != nullptr; temp = temp->pNext)
		sum += temp->baiHat.time;

	return { sum / 60,sum % 60 };

}

void Search(List l)
{
	int key = -1;
	cout << "Nhap thu tu cua bai hat: ";
	cin >> key;
	if (key < 1)
		cout << "\nKhong co bai hat";
	else
	{
		int i = 1;
		Node* temp = l.pHead;
		while (i <= key && temp != nullptr)
		{
			if (i == key)
			{
				if (temp != nullptr)
				{
					cout << endl << i << ". ";
					Print(temp->baiHat);
					break;
				}
				else
				{
					cout << "\nKhong co bai hat";
					break;
				}
			}

			temp = temp->pNext;
			i++;
		}

	}

}

void Print(BaiHat bh)
{
	cout << bh.name << " - " << bh.singerName << " - " << bh.time << "s";
}