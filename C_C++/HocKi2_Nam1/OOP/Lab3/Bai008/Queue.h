#ifndef _Stack_h
#define _Stack_h
#include "../Bai005/List.h"

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
#endif // !_Stack_h

