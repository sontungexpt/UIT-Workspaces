#include "Queue.h"

Queue::Queue()
{
    Init();
}

Queue::Queue(int value)
{
    Init();
    EnQueue(value);
}

Queue::Queue(const Queue &x)
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

void Queue::operator=(const Queue &oldQueue)
{
    list = oldQueue.list;
}
