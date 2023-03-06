//STT: 
//Họ và tên: Trần Võ Sơn Tùng
//Buổi 03 - Bài 01
//Ghi chú, hoặc Lưu ý: dùng class để lập trình stack


#include <conio.h>
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
void Pause();
int main()
{
	char key = 0;
	Stack st;
	while (key != '27')
	{
		system("cls");
		cout << "1: Initilize the stack\n";
		cout << "2: Is the stack empty\n";
		cout << "3: Is the stack full\n";
		cout << "4: Input an element to stack\n";
		cout << "5: Print the top element and remove it from the stack\n";
		cout << "6: Print the top element\n";
		cout << "ESC: Exit";
		cout << "Choose your choice: ";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			st.Init();
			cout << "Successful!";
			Pause();
			break;
		case '2':
			system("cls");
			if (st.IsEmpty())
				cout << "Stack is empty";
			else
				cout << "Stack isn't empty";
			Pause();
			break;
		case'3':
			system("cls");
			cout << "Stack made by LinkedList so it has no limit";
			Pause();
			break;
		case '4':
			system("cls");
			int n;
			cout << "Input the numbers of element you want to push to stack: ";
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				int ele;
				cout << "Input element " << i << ": ";
				cin >> ele;
				st.Push(ele);
			}
			Pause();
			break;
		case'5':
			system("cls");
			if (st.IsEmpty())
				cout << "Stack is empty!";
			else
			{
				cout << "Top element is: " << st.Pop();
				cout << "\nTop element is removed from stack!";
			}
			Pause();
			break;
		case'6':
			system("cls");
			if (st.IsEmpty())
				cout << "Stack is empty!";
			else
				cout << "Top element is: " << st.Top();
			Pause();
			break;
		case 27:
		{
			system("cls");
			cout << "Are you sure to exit the program?\n";
			cout << "Yes. Enter.\n";
			cout << "Back To Home. ESC.\n";
			cout << "Choose your choice: \n";
			char choice;
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
		}
		default:
			break;
		}
	}
}

void Pause()
{
	cout << "\nPress enter to continue!\n";
	char enter;
	do
	{
		enter = _getch();
	} while (enter != 13);
}

//begin List
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