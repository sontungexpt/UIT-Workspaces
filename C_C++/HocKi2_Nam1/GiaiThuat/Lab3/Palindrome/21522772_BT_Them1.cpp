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

class Queue
{
private:
	List list;

public:
	//constructor
	Queue();
	Queue(int);
	Queue(const Queue&);

	//method
	void Init();
	void EnQueue(int);
	int Front();
	int Rear();
	int DeQueue();
	int Count();
	bool IsEmpty();

	//overload operator
	void operator = (const Queue&);

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

bool IsPalindrome(string);

int main()
{
	string str;
	cout << "Input your string to check: ";
	getline(cin, str,'\n');
	if (IsPalindrome(str))
		cout << str << " is Palindrome";
	else
		cout << str << " is not Palindrome";
	return 0;
}

bool IsPalindrome(string str)
{
	Stack backward;
	Queue forward;

	for (int i = 0; i < str.length(); i++)
	{
		backward.Push(str.at(i));
		forward.EnQueue(str.at(i));
	}
	while (!backward.IsEmpty())
	{
		if (backward.Pop() != forward.DeQueue())
			return 0;
	}
	return 1;
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

//begin queue
Queue::Queue()
{
	Init();
}

Queue::Queue(int value)
{
	Init();
	EnQueue(value);
}

Queue::Queue(const Queue& x)
{
	list = x.list;
}

void Queue::Init()
{
	list.Init();
}

int Queue::Front()
{
	if (list.IsEmpty())
		return -1;
	return list.GetPHead()->info;
}

int Queue::Rear()
{
	if (list.IsEmpty())
		return -1;
	return list.GetPTail()->info;
}

void Queue::EnQueue(int value)
{
	list.AddTail(list.CreateNode(value));
}

int Queue::DeQueue()
{
	if (list.IsEmpty())
		return -1;
	return list.DeleteHead()->info;
}

int Queue::Count()
{
	return list.Count();
}

bool Queue::IsEmpty()
{
	return list.IsEmpty();
}

void Queue::operator=(const Queue& oldQueue)
{
	list = oldQueue.list;
}
//end queue

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