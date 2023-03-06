#ifndef _Queue_h
#define _Queue_h
#include "List.h"

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
#endif
