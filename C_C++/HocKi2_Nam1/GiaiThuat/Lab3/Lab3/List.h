#ifndef _List_h
#define _List_h
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

    //constructor
    List();
    List(int);
    List(const List&);

    //properties
    Node* GetPHead();
    void SetPHead(Node*);
    Node* GetPTail();
    void SetPTail(Node*);
    
    //method
    void Init();
    bool IsEmpty();
    Node* CreateNode(int);
    void AddTail(Node*);
    void AddHead(Node*);
    Node* DeleteHead();
    int Count();

    //overload operator
    void operator = (const List&);
};
#endif