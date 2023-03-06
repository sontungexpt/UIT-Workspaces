#ifndef _List_h
#define _List_h
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
#pragma region Constructor
	List();
	List(int);
	List(const List&);
#pragma endregion

#pragma region Properties
	Node* GetPHead();
	void SetPHead(Node*);
	Node* GetPTail();
	void SetPTail(Node*);
#pragma endregion

#pragma region Method
	void Init();
	bool IsEmpty();
	Node* CreateNode(int);
	void AddTail(Node*);
	void AddHead(Node*);
	Node* DeleteHead();
	int Count();

	//overload operator
	void operator = (const List&);
#pragma endregion
	
};

#endif // !_List_h





