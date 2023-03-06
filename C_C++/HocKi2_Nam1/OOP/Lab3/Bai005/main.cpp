#include "Stack.h"
void Pause();


int main()
{
	char key = 0;
	Stack st;
	while (key != '27')
	{
		system("cls");
		cout << "1: Initilize the stack\n";
		cout << "2: Is the stack empty\n";
		cout << "3: Is the stack full\n";
		cout << "4: Input an element to stack\n";
		cout << "5: Print the top element and remove it from the stack\n";
		cout << "6: Print the top element\n";
		cout << "ESC: Exit\n";
		cout << "Choose your choice: ";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			st.Init();
			cout << "Successful!";
			Pause();
			break;
		case '2':
			system("cls");
			if (st.IsEmpty())
				cout << "Stack is empty";
			else
				cout << "Stack isn't empty";
			Pause();
			break;
		case'3':
			system("cls");
			cout << "Stack made by LinkedList so it has no limit";
			Pause();
			break;
		case '4':
			system("cls");
			int n;
			cout << "Input the numbers of element you want to push to stack: ";
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				int ele;
				cout << "Input element " << i << ": ";
				cin >> ele;
				st.Push(ele);
			}
			Pause();
			break;
		case'5':
			system("cls");
			if (st.IsEmpty())
				cout << "Stack is empty!";
			else
			{
				cout << "Top element is: " << st.Pop();
				cout << "\nTop element is removed from stack!";
			}
			Pause();
			break;
		case'6':
			system("cls");
			if (st.IsEmpty())
				cout << "Stack is empty!";
			else
				cout << "Top element is: " << st.Top();
			Pause();
			break;
		case 27:
		{
			system("cls");
			cout << "Are you sure to exit the program?\n";
			cout << "Yes. Enter.\n";
			cout << "Back To Home. ESC.\n";
			cout << "Choose your choice: \n";
			char choice;
			do
			{
				choice = _getch();
				switch (choice)
				{
				case 13:
					exit(0);
					break;

				case 27:
					key = 0;
					break;

				default:
					break;
				}
			} while (choice != 13 && choice != 27);
			break;
		}
		default:
			break;
		}
	}
}



void Pause()
{
	cout << "\nPress enter to continue!\n";
	char enter;
	do
	{
		enter = _getch();
	} while (enter != 13);
}
