#include "Queue.h"

void Pause();

int main()
{
	char key = 0;
	Queue qu;
	while (key != '27')
	{
		system("cls");
		cout << "1: Initilize the queue\n";
		cout << "2: Is the queue empty\n";
		cout << "3: Is the queue full\n";
		cout << "4: Input an element to queue\n";
		cout << "5: Print the top element and remove it from the queue\n";
		cout << "6: Print the top and rear element\n";
		cout << "ESC: Exit";
		cout << "Choose your choice: ";
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			qu.Init();
			cout << "Successful!";
			Pause();
			break;
		case '2':
			system("cls");
			if (qu.IsEmpty())
				cout << "Queue is empty";
			else
				cout << "Queue isn't empty";
			Pause();
			break;
		case'3':
			system("cls");
			cout << "Queue made by LinkedList so it has no limit";
			Pause();
			break;
		case '4':
			system("cls");
			int n;
			cout << "Input the numbers of element you want to enqueue to queue: ";
			cin >> n;
			for (int i = 1; i <= n; i++)
			{
				int ele;
				cout << "Input element " << i << ": ";
				cin >> ele;
				qu.EnQueue(ele);
			}
			Pause();
			break;
		case'5':
			system("cls");
			if (qu.IsEmpty())
				cout << "Queue is empty!";
			else
			{
				cout << "Front element is: " << qu.DeQueue();
				cout << "\nFront element is removed from queue!";
			}
			Pause();
			break;
		case'6':
			system("cls");
			if (qu.IsEmpty())
				cout << "Queue is empty!";
			else
			{
				cout << "Front element is: " << qu.Front();
				cout << "\nRear element is: " << qu.Rear();
			}
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