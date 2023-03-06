#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct node
{
    int info;
    struct node* pNext;
    struct node* pPrev;
};
typedef struct node NODE;
struct list
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct list LIST;

//initilize function
void Init(LIST&);
int IsEmpty(LIST);
NODE* GetNode(int );
void AddTail(LIST&, NODE*);
int Nhap(LIST&, string);
void Xuat(LIST l);
int DemNode(LIST);
int Xuat(LIST, string);
void InterchangeSort(LIST &);
int main()
{
    LIST lst;
    for (int i = 1; i <= 13; i++)
    {
        string filename = "intdata";
        if (i < 10)
            filename += '0';
        filename += to_string(i);
        string filenameinp = filename;
        filenameinp += ".inp";
        if (Nhap(lst, filenameinp) == 1)
        {
            InterchangeSort(lst);
            string filenameout = filename;
            filenameout += ".out";
            Xuat(lst, filenameout);
            cout << "\n" << filenameinp;
            cout << "\n" << filenameout;
        }
        else
            cout << "\n Khong mo duoc file " << filename << "\n";
    }
    cout << "\n\n\n";
    return 1;
}

//function
void Init(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
int IsEmpty(LIST l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}
NODE* GetNode(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}
void AddTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}
int Nhap(LIST& l, string filename)
{
    ifstream fi(filename);
    if (fi.fail() == true)
        return 0;
    int n;
    int x;
    fi >> n;
    Init(l);
    for (int i = 1; i <= n; i++)
    {
        fi >> x;
        NODE* p = GetNode(x);
        if (p != NULL)
            AddTail(l, p);
    }
    return 1;
}
void Xuat(LIST l)
{
    NODE* p = l.pHead;
    while (p != NULL)
    {
        cout << p->info;
        p = p->pNext;
    }
}
int DemNode(LIST l)
{
    int dem = 0;
    NODE* p = l.pHead;
    while (p != NULL)
    {
        dem++;
        p = p->pNext;
    }
    return dem;
}
int Xuat(LIST l, string filename)
{
    ofstream fo(filename);
    if (fo.fail() == true)
        return 0;
    fo << setw(5) << DemNode(l) << endl;
    NODE* p = l.pHead;
    while (p != NULL)
    {
        fo << setw(5) << p->info;
        p = p->pNext;
    }
    return 1;
}
void InterchangeSort(LIST& l)
{
    for (NODE* p = l.pHead; p->pNext != NULL; p = p->pNext)
        for (NODE* q = p->pNext; q != NULL; q = q->pNext)
            if (p->info > q->info)
                swap(p->info, q->info);
}