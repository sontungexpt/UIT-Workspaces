#ifndef _LinkedList_h
#define _LinkedList_h
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

template <typename T>
struct Node
{
public:
	T data;
	struct Node<T>* pNext;
	struct Node<T>* pPrev;
	Node();
};

template <typename T>
class LinkedList
{
private:
	Node<T>* pHead;
	Node<T>* pTail;
	int size;

public:
	//constructor
	LinkedList();
	LinkedList(T);
	LinkedList(const LinkedList<T>&);

	//properties
	Node<T>* GetPHead();
	void SetPHead(Node<T>*);
	Node<T>* GetPTail();
	void SetPTail(Node<T>*);

	//method
	
	//Initialize the list
	void Init();
	//check if the list is empty
	bool IsEmpty();
	//return the value at the index 
	T At(int);
	//print all element in the list
	void Print();
	//automatically enter the element in the list
	void AutoInput();
	//return the numbers of element in the list
	int Size();
	//insert an element to the last index
	void AddTail(Node<T>*);
	//insert an element to the first index
	void AddHead(Node<T>*);
	//reverse the element in the list
	void Reverse();
	//return the max value in the list
	T Max();
	//return the min value in the list
	T Min();
	Node<T>* CreateNode(T);
	//return the first element and delete it incompletely
	Node<T>* DeleteHead();
	//delete the first element completely
	void RemoveHead();
	//return the last element and delete it incompletely
	Node<T>* DeleteTail();
	//delete the last element completely
	void RemoveTail();
	//sort the element in the list
	void Sort();
	void Clear();


	//overload operator
	LinkedList<T> operator = (const LinkedList<T>&);
};

template <typename T>
Node<T>::Node()
{
	this->pNext = nullptr;
	this->pPrev = nullptr;
}

//constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	pHead = nullptr;
	pTail = nullptr;
	size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(T value)
{
	pHead = nullptr;
	pTail = nullptr;
	size = 0;
	AddTail(this->CreateNode(value));
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& x)
{
	pHead = nullptr;
	pTail = nullptr;
	size = 0;
	for (Node<T>* temp = x.pHead; temp != nullptr; temp = temp->pNext)
		AddTail(CreateNode(temp->data));
}

//properties
template <typename T>
Node<T>* LinkedList<T>::GetPHead()
{
	return pHead;
}

template <typename T>
void LinkedList<T>::SetPHead(Node<T>* pHead)
{
	this->pHead->data = pHead->data;
}

template <typename T>
Node<T>* LinkedList<T>::GetPTail()
{
	return pTail;
}

template <typename T>
void LinkedList<T>::SetPTail(Node<T>* pTail)
{
	this->pTail->data = pTail->data;
}

template <typename T>
void LinkedList<T>::Init()
{
	pHead = nullptr;
	pTail = nullptr;
	size = 0;
}

template <typename T>
bool LinkedList<T>::IsEmpty()
{
	if (pHead == nullptr || pTail == nullptr)
		return 1;
	return 0;
}

template <typename T>
Node<T>* LinkedList<T>::CreateNode(T data)
{
	Node<T>* newEle = new Node<T>;
	if (newEle == nullptr)
		return nullptr;
	newEle->data = data;
	newEle->pNext = nullptr;
	newEle->pPrev = nullptr;
	return newEle;
}

template <typename T>
void LinkedList<T>::AddTail(Node<T>* newEle)
{
	if (IsEmpty())
		pHead = pTail = newEle;
	else
	{
		newEle->pPrev = pTail;
		pTail->pNext = newEle;
		pTail = newEle;
	}
	size++;
}

template <typename T>
void LinkedList<T>::AddHead(Node<T>* newEle)
{
	if (IsEmpty())
		pHead = pTail = newEle;
	else
	{
		newEle->pNext = pHead;
		pHead->pPrev = newEle;
		pHead = newEle;
	}
	size++;
}

template <typename T>
Node<T>* LinkedList<T>::DeleteHead()
{
	if (IsEmpty())
		return nullptr;
	Node<T>* temp = pHead;
	pHead = pHead->pNext;
	if (IsEmpty())
		pTail = nullptr;
	else
		pHead->pPrev = nullptr;
	size--;
	return temp;
}

template <typename T>
void LinkedList<T>::RemoveHead()
{
	Node<T>* temp = this->DeleteHead();
	delete temp;
	temp = nullptr;
}

template <typename T>
Node<T>* LinkedList<T>::DeleteTail()
{
	if (IsEmpty())
		return nullptr;
	Node<T>* temp = pTail;
	pTail = pTail->pPrev;
	if (IsEmpty())
		pHead = nullptr;
	else
		pTail->pNext = nullptr;
	size--;
	return temp;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
	Node<T>* temp = this->DeleteTail();
	delete temp;
	temp = nullptr;
}

template <typename T>
int LinkedList<T>::Size()
{
	return size;
}

template <typename T>
void LinkedList<T>::Print()
{
	cout << "\nList: ";
	for (Node<T>* temp = pHead; temp != nullptr; temp = temp->pNext)
		cout << temp->data << "  ";
}

template <typename T>
LinkedList<T> LinkedList<T>::operator = (const LinkedList<T>& oldLinkedList)
{
	Init();
	for (Node<T>* temp = oldLinkedList.pHead; temp != nullptr; temp = temp->pNext)
		AddTail(CreateNode(temp->data));
	return *this;
}

template <typename T>
T LinkedList<T>::At(int index)
{
	if (index >= size)
		return -1;
	else
	{
		if (index <= size / 2)
		{
			Node<T>* temp = pHead;
			for (int i = 0; i < index; i++)
				temp = temp->pNext;
			return temp->data;
		}
		else
		{
			Node<T>* temp = pTail;
			for (int i = size - 1; i > index; i--)
				temp = temp->pPrev;
			return temp->data;
		}
	}

}

template <typename T>
void LinkedList<T>::AutoInput()
{
	srand(time(NULL));
	cout << "Input range of the capacity of the list: [a;b]\n";
	int a;
	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	int b;
	cin >> b;
	int n = rand() % (b - a + 1) + a;
	cout << "Input range of the random number: [a;b]\n";
	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;
	for (int i = 0; i < n; i++)
	{
		int x = rand() % (b - a + 1) + a;
		AddTail(CreateNode(x));
	}
}

template <typename T>
T LinkedList<T>::Max()
{
	if (IsEmpty())
		return 0;
	Node<T>* max = pHead;
	for (Node<T>* temp = pHead->pNext; temp != nullptr; temp = temp->pNext)
		if (max->data < temp->data)
			max = temp;
	return max->data;
}

template <typename T>
T LinkedList<T>::Min()
{
	if (IsEmpty())
		return 0;
	Node<T>* min = pHead;
	for (Node<T>* temp = pHead->pNext; temp != nullptr; temp = temp->pNext)
		if (min->data > temp->data)
			min = temp;
	return min->data;
}

template <typename T>
void LinkedList<T>::Reverse()
{
	LinkedList<T> listReversed;
	while (!IsEmpty())
	{
		listReversed.AddTail(listReversed.CreateNode(pTail->data));
		this->RemoveTail();
	}
	*this = listReversed;
}

template <typename T>
void LinkedList<T>::Sort()
{
	for (Node<T>* temp = pHead; temp->pNext != nullptr; temp = temp->pNext)
		for (Node<T>* temp1 = temp->pNext; temp1 != nullptr; temp1 = temp1->pNext)
			if (temp->data > temp1->data)
				swap(temp->data, temp1->data);
}
#endif