#include "Stack.h"

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