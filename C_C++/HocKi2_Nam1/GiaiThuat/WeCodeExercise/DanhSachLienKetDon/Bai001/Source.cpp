
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* link;
};

void _append(node**, int);

void _append(node** List, int info)
{

}



void _display(node* q)
{
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}

int main()
{
    node* head;
    head = NULL;

    _append(&head, 1);
    _append(&head, 2);
    _append(&head, 3);
    _append(&head, 4);
    _append(&head, 17);

    _display(head);

    return 0;
}