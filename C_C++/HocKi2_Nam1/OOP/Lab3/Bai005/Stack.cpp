#include "Stack.h"

#pragma region Constructor
Stack::Stack()
{
	list.Init();
}

Stack::Stack(int value)
{
	list.Init();
	Push(value);
}

Stack::Stack(const Stack& st)
{
	this->list = st.list;
}
#pragma endregion


#pragma region Method
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

#pragma endregion
