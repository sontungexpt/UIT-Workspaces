#ifndef _Stack_h
#define _Stack_h
#include "List.h"


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
#endif
