#ifndef _Stack_h
#define _Stack_h
#include "List.h"
class Stack
{
private:
	List list;

public:
#pragma region Constructor
	Stack();
	Stack(int);
	Stack(const Stack&);
#pragma endregion

#pragma region Properties

#pragma endregion

#pragma region Method
	//method
	void Init();
	void Push(int);
	int Top();
	int Pop();
	int Count();
	bool IsEmpty();

	//overload operator
	void operator = (const Stack&);
#pragma endregion

};

#endif // !_Stack_h

