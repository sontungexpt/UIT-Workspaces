#include "List.h"

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