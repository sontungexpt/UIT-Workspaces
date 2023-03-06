// STT:
// Họ và tên: Trần Võ Sơn Tùng
// Buổi 04 - Bài 01
// Ghi chú, hoặc Lưu ý: ......

#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

struct NODE
{
	int data;
	struct NODE* pLeft;
	struct NODE* pRight;
};

typedef struct NODE NODE;
typedef NODE* Tree;
void Init(Tree&);
NODE* CreateNode(int);
bool IsEmpty(Tree);
void Insert(Tree&, int);
void PrintLNR(Tree);
void PrintNLR(Tree);
void PrintLRN(Tree);
int Count(Tree);
void PrintMenu();
void Input(Tree&);
void AutoInput(Tree&);
void Pause();
bool IsExist(Tree, int);
void Delete(Tree&, int);
void Replace(Tree& nodeReplaced, Tree& replacementNode);
int CountLessThan(Tree, int);
int CountGreaterThan(Tree, int);
int SumOddNodes(Tree);
int CountLeaf(Tree);

int main()
{
	srand(time(NULL));
	Tree tree;
	Init(tree);
	char key1;
	char key;
	int number;
	do
	{
		system("cls");
		PrintMenu();
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			cout << "Add a number to binary tree: ";
			cin >> number;
			Insert(tree, number);
			break;
		case '2':
			system("cls");
			Init(tree);
			Input(tree);
			break;
		case '3':
			system("cls");
			Init(tree);
			AutoInput(tree);
			Pause();
			break;
		case '4':
			system("cls");
			if (IsEmpty(tree))
				cout << "You haven't input tree yet";
			else
			{
				cout << "\n\nLNR:\n";
				PrintLNR(tree);
				cout << "\n\nNLR:\n";
				PrintNLR(tree);
				cout << "\n\nLRN:\n";
				PrintLRN(tree);
			}
			Pause();
			break;
		case '5':
			system("cls");
			cout << "1. Input your value: ";
			cout << "\n2. Auto input your value: ";
			key1 = _getch();
			system("cls");
			switch (key1)
			{
			case '1':
				cout << "Input your number that you want to search: ";
				cin >> number;
				if (IsExist(tree, number) == true)
					cout << "Exist";
				else
					cout << "Not exist";
				Pause();
				break;
			case '2':
				number = rand() % (800 - 300 + 1) + 300;
				if (IsExist(tree, number) == true)
					cout << "Exist";
				else
					cout << "Not exist";
				Pause();
				break;
			default:
				break;
			}
			break;
		case '6':
			system("cls");
			cout << "Input your number you want to delete: ";
			cin >> number;
			Delete(tree, number);
			Pause();
			break;
		case '7':
			system("cls");
			cout << "The numbers of node in tree is: " << Count(tree);
			Pause();
			break;
		case '8':
			system("cls");
			cout << "Input your conditional number: ";
			cin >> number;
			cout << "The number of nodes less than x in the tree is: " << CountLessThan(tree, number);
			Pause();
			break;
		case '9':
			system("cls");
			cout << "Input your conditional number: ";
			cin >> number;
			cout << "The number of nodes less than x in the tree is: " << CountLessThan(tree, number);
			Pause();
			break;
		case '0':
			system("cls");
			cout << "Sum of odd nodes in tree: " << SumOddNodes(tree);
			Pause();
			break;
		case 'a':
			system("cls");
			cout << "The numbers of leaf node in tree is: " << CountLeaf(tree);
			Pause();
			break;
		default:
			break;
		}
	} while (key != 27);

	return 0;
}

void PrintMenu()
{
	cout << "1. Insert NODE";
	cout << "\n2. Input binary tree";
	cout << "\n3. Auto Input binary tree";
	cout << "\n4. Print by NLR, LNR, LRN: ";
	cout << "\n5. Search a number in tree: ";
	cout << "\n6. Delete a number in tree: ";
	cout << "\n7. Count all nodes in binary tree: ";
	cout << "\n8. Count all nodes less than any number: ";
	cout << "\n9. Count all nodes greater than any number: ";
	cout << "\n0. Calculate sum of all odd nodes in binary tree:";
	cout << "\na. Count all leaf nodes in binary tree: ";
	cout << "\nESC: Exit";
}

void AutoInput(Tree& tree)
{
	int amount = rand() % (20 - 10 + 1) + 10;
	for (int i = 0; i < amount; i++)
	{
		int number = rand() % (1358 - (-358) + 1) + (-358);
		Insert(tree, number);
	}
}

void Input(Tree& tree)
{
	while (true)
	{
		int number = 0;
		cout << "\nAdd a number to binary tree: ";
		cin >> number;
		Insert(tree, number);
		cout << "Press enter to continue adding!, ESC to pause adding\n";
		char enter;
		do
		{
			enter = _getch();
		} while (enter != 13 && enter != 27);
		if (enter == 27)
			break;
	}
}

void Pause()
{
	cout << "\nPress enter to continue your program!\n";
	char enter;
	do
	{
		enter = _getch();
	} while (enter != 13);
}

bool IsEmpty(Tree tree)
{
	if (tree == nullptr)
		return 1;
	return 0;
}

void Init(Tree& tree)
{
	tree = nullptr;
}

NODE* CreateNode(int data)
{
	NODE* newNODE = new NODE;
	if (newNODE == nullptr)
		return nullptr;
	newNODE->data = data;
	newNODE->pLeft = nullptr;
	newNODE->pRight = nullptr;
	return newNODE;
}

void Insert(Tree& root, int data)
{
	if (root == nullptr)
		root = CreateNode(data);
	else if (root->data == data)
		return;
	else if (root->data > data)
		Insert(root->pLeft, data);
	else
		Insert(root->pRight, data);
}

void PrintLNR(Tree tree)
{
	if (tree == nullptr)
		return;
	PrintLNR(tree->pLeft);
	cout << endl
		<< tree->data << '\t' << &tree << "\tpLeft: " << &tree->pLeft << "\t\tpRight : " << &tree->pRight;
	PrintLNR(tree->pRight);
}

void PrintNLR(Tree tree)
{
	if (tree == nullptr)
		return;
	cout << endl
		<< tree->data << '\t' << &tree << "\tpLeft: " << &tree->pLeft << "\t\tpRight : " << &tree->pRight;
	PrintNLR(tree->pLeft);
	PrintNLR(tree->pRight);
}

void PrintLRN(Tree tree)
{
	if (tree == nullptr)
		return;
	PrintLRN(tree->pLeft);
	PrintLRN(tree->pRight);
	cout << endl
		<< tree->data << '\t' << &tree << "\tpLeft: " << &tree->pLeft << "\t\tpRight : " << &tree->pRight;
}

bool IsExist(Tree tree, int x)
{
	if (tree == nullptr)
		return false;
	if (tree->data == x)
		return true;
	else if (tree->data > x)
		return IsExist(tree->pLeft, x);
	else
		return IsExist(tree->pRight, x);
}

void Replace(Tree& nodeReplaced, Tree& replacementNode)
{
	if (replacementNode->pLeft != nullptr)
		Replace(nodeReplaced, replacementNode->pLeft);
	else
	{
		nodeReplaced->data = replacementNode->data;
		nodeReplaced = replacementNode;
		replacementNode = replacementNode->pRight;
	}
}

void Delete(Tree& tree, int x)
{
	if (IsExist(tree, x))
	{
		if (tree->data < x)
			Delete(tree->pRight, x);
		else if (tree->data > x)
			Delete(tree->pLeft, x);
		else
		{
			NODE* temp = tree;
			if (tree->pLeft == nullptr)
				tree = tree->pRight;
			else if (tree->pRight == nullptr)
				tree = tree->pLeft;
			else
			{
				NODE* tempRight = tree->pRight;
				Replace(temp, tempRight);
			}
			delete temp;
		}
	}
	else
		cout << "Not exist number in binary tree";
}

int Count(Tree tree)
{
	if (tree == nullptr)
		return 0;
	int a = Count(tree->pLeft);
	int b = Count(tree->pRight);
	return a + b + 1;
}

int CountLeaf(Tree tree)
{
	if (tree == nullptr)
		return 0;
	int a = CountLeaf(tree->pLeft);
	int b = CountLeaf(tree->pRight);
	if (tree->pLeft == nullptr && tree->pRight == nullptr)
		return a + b + 1;
	else
		return a + b;
}

int CountLessThan(Tree tree, int x)
{
	if (tree == nullptr)
		return 0;
	int a = CountLessThan(tree->pLeft, x);
	int b = CountLessThan(tree->pRight, x);
	if (tree->data < x)
		return a + b + 1;
	else
		return a + b;
}

int CountGreaterThan(Tree tree, int x)
{
	if (tree == nullptr)
		return 0;
	int a = CountGreaterThan(tree->pLeft, x);
	int b = CountGreaterThan(tree->pRight, x);
	if (tree->data > x)
		return a + b + 1;
	else
		return a + b;
}

int SumOddNodes(Tree tree)
{
	if (tree == nullptr)
		return 0;
	int a = SumOddNodes(tree->pLeft);
	int b = SumOddNodes(tree->pRight);
	if (tree->data % 2 != 0)
		return a + b + tree->data;
	return a + b;
}