#include "Farm.h"

void Farm::Input()
{
	catles.resize(3);
	do {
		cout << "\nInput the amount of cow: ";
		cin >> amountOfCow;
	} while (amountOfCow < 0);

	if (amountOfCow != 0)
	{
		catles[0].resize(0);
		for (int i = 0; i < amountOfCow; i++)
			catles[0].push_back(new Cow);
	}

	do {
		cout << "\nInput the amount of sheep: ";
		cin >> amountOfSheep;
	} while (amountOfSheep < 0);

	if (amountOfSheep != 0)
	{
		catles[1].resize(0);
		for (int i = 0; i < amountOfSheep; i++)
			catles[1].push_back(new Sheep);
	}

	do {
		cout << "\nInput the amount of goat: ";
		cin >> amountOfGoat;
	} while (amountOfGoat < 0);

	if (amountOfGoat != 0)
	{
		catles[2].resize(0);
		for (int i = 0; i < amountOfGoat; i++)
			catles[2].push_back(new Goat);
	}
}

int Farm::GetNumbersOf(string type)
{
	int sum = 0;
	if (type == "Cow")
		for (int i = 0; i < catles[0].size(); i++)
			sum += catles[0][i]->GetLastAmount();
	else if (type == "Sheep")
		for (int i = 0; i < catles[1].size(); i++)
			sum += catles[1][i]->GetLastAmount();
	else if (type == "Goat")
		for (int i = 0; i < catles[2].size(); i++)
			sum += catles[2][i]->GetLastAmount();
	else
		cout << "\nWrong type\n";
	return sum;
}

int Farm::GetNumberOfMilk()
{
	srand(time(NULL));
	int sum = 0;
	for (int i = 0; i < catles.size(); i++)
		for (int j = 0; j < catles[i].size(); j++)
		{
			catles[i][j]->SetMilkAmount();
			sum += catles[i][j]->GetMilkAmount();
		}
	return sum;
}

void Farm::Sound()
{
	for (int i = 0; i < catles.size(); i++)
		for (int j = 0; j < catles[i].size(); j++)
		{
			//catles[i][j]->SetSound();
			catles[i][j]->Sound();
		}
}

void Farm::Print()
{
	cout << "\n\nNumber of cow after a litter: " << GetNumbersOf("Cow");
	cout << "\nNumber of sheep after a litter: " << GetNumbersOf("Sheep");
	cout << "\nNumber of goat after a litter: " << GetNumbersOf("Goat");
	cout << "\nThe sum of milk liters: " << GetNumberOfMilk();
}