//STT: 39
//Họ và tên: Trần Võ Sơn Tùng
//Buổi 03 - Bài thêm 02
//Ghi chú, hoặc Lưu ý: dùng class để lập trình stack
#include <string>
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int info;
	struct Node* pNext;
};

class List
{
private:
	Node* pHead;
	Node* pTail;
	int length;

public:

	//constructor
	List();
	List(int);
	List(const List&);

	//properties
	Node* GetPHead();
	void SetPHead(Node*);
	Node* GetPTail();
	void SetPTail(Node*);

	//method
	void Init();
	bool IsEmpty();
	Node* CreateNode(int);
	void AddTail(Node*);
	void AddHead(Node*);
	Node* DeleteHead();
	int Count();

	//overload operator
	void operator = (const List&);
};

class Stack
{
private:
	List list;

public:
	//constructor
	Stack();
	Stack(int);
	Stack(const Stack&);

	//method
	void Init();
	void Push(int);
	int Top();
	int Pop();
	int Count();
	bool IsEmpty();

	//overload operator
	void operator = (const Stack&);
};


string ChangeToHexa(int);
char ConvertToChar(short int);

int main()
{
	int n;
	cout << "Input the Decimal number : ";
	cin >> n;
	cout << "The Hexa decimal: " << ChangeToHexa(n);
	return 0;
}

string ChangeToHexa(int decimal)
{
	Stack stored;
	string hexa = "";
	while (decimal > 0)
	{
		int left = decimal % 16;
		stored.Push(left);
		decimal /= 16;
	}
	while(!stored.IsEmpty())
		hexa += ConvertToChar(stored.Pop());
	return hexa;
}

char ConvertToChar(short int n)
{
	if (n == 0)
		return '0';
	else if (n == 1)
		return '1';
	else if (n == 2)
		return '2';
	else if (n == 3)
		return '3';
	else if (n == 4)
		return '4';
	else if (n == 5)
		return '5';
	else if (n == 6)
		return '6';
	else if (n == 7)
		return '7';
	else if (n == 8)
		return '8';
	else if (n == 9)
		return'9';
	else if (n == 10)
		return 'A';
	else if (n == 11)
		return 'B';
	else if (n == 12)
		return 'C';
	else if (n == 13)
		return 'D';
	else if (n == 14)
		return 'E';
	return 'F';
}


//begin list
List::List()
{
	Init();
}

List::List(int value)
{
	Init();
	AddTail(CreateNode(value));
}

List::List(const List& x)
{
	Init();
	for (Node* temp = x.pHead; temp != nullptr; temp = temp->pNext)
		AddTail(CreateNode(temp->info));
}

Node* List::GetPHead()
{
	return pHead;
}

void List::SetPHead(Node* pHead)
{
	this->pHead = pHead;
}

Node* List::GetPTail()
{
	return pTail;
}

void List::SetPTail(Node* pTail)
{
	this->pTail = pTail;
}

void List::Init()
{
	pHead = nullptr;
	pTail = nullptr;
	int length = 0;
}

bool List::IsEmpty()
{
	if (pHead == nullptr)
		return 1;
	return 0;
}

Node* List::CreateNode(int info)
{
	Node* newEle = new Node;
	if (newEle == nullptr)
		return nullptr;
	newEle->info = info;
	newEle->pNext = nullptr;
	return newEle;
}

void List::AddTail(Node* newEle)
{
	if (IsEmpty())
		pHead = pTail = newEle;
	else
	{
		pTail->pNext = newEle;
		pTail = newEle;
	}
	length++;
}

void List::AddHead(Node* newEle)
{
	if (IsEmpty())
		pHead = pTail = newEle;
	else
	{
		newEle->pNext = pHead;
		pHead = newEle;
	}
	length++;
}

Node* List::DeleteHead()
{
	if (IsEmpty())
		return nullptr;
	Node* temp = pHead;
	pHead = pHead->pNext;
	if (IsEmpty())
		pTail = nullptr;
	length--;
	return temp;
}

int List::Count()
{
	return length;
}

void List::operator = (const List& oldList)
{
	Init();
	for (Node* temp = oldList.pHead; temp != nullptr; temp = temp->pNext)
		AddTail(CreateNode(temp->info));

}

//end list

//begin stack
Stack::Stack()
{
	Init();
}

Stack::Stack(int value)
{
	Init();
	Push(value);
}

Stack::Stack(const Stack& st)
{
	list = st.list;
}

void Stack::Init()
{
	list.Init();
}

int Stack::Top()
{
	if (list.IsEmpty())
		return -1;
	return list.GetPHead()->info;
}

void Stack::Push(int value)
{
	list.AddHead(list.CreateNode(value));
}

int Stack::Pop()
{
	if (list.IsEmpty())
		return -1;
	return list.DeleteHead()->info;
}

int Stack::Count()
{
	return list.Count();
}

void Stack::operator = (const Stack& oldStack)
{
	list = oldStack.list;
}

bool Stack::IsEmpty()
{
	return list.IsEmpty();
}

//end stack