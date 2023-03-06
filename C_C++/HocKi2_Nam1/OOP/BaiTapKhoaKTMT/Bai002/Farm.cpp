#include "Farm.h"

void Farm::Input()
{
	cowList.resize(0);
	goatList.resize(0);
	sheepList.resize(0);

	do {
		cout << "\nInput the amount of cow: ";
		cin >> amountOfCow;
	} while (amountOfCow < 0);

	if (amountOfCow != 0)
	{
		for (int i = 0; i < amountOfCow; i++)
		{
			Cow newCow;
			cowList.push_back({});
		}
	}

	do {
		cout << "\nInput the amount of sheep: ";
		cin >> amountOfSheep;
	} while (amountOfSheep < 0);

	if (amountOfSheep != 0)
	{
		for (int i = 0; i < amountOfSheep; i++)
		{
			Sheep newSheep;
			sheepList.push_back({});
		}
	}

	do {
		cout << "\nInput the amount of goat: ";
		cin >> amountOfGoat;
	} while (amountOfGoat < 0);

	if (amountOfGoat != 0)
	{
		for (int i = 0; i < amountOfGoat; i++)
		{
			Goat newGoat;
			goatList.push_back({});
		}
	}
}

int Farm::GetNumbersOf(string type)
{
	srand(time(NULL));
	int sum = 0;
	if (type == "Cow")
		for (int i = 0; i < cowList.size(); i++)
		{
			cowList[i].SetChildAmount();
			cout << "\nChild of cow " << i + 1 << ": " << cowList[i].GetChildAmount();
			sum += cowList[i].GetLastAmount();
		}
	else if (type == "Sheep")
		for (int i = 0; i < sheepList.size(); i++)
		{
			sheepList[i].SetChildAmount();
			cout << "\nChild of sheep " << i + 1 << ": " << sheepList[i].GetChildAmount();
			sum += sheepList[i].GetLastAmount();
		}
	else if (type == "Goat")
		for (int i = 0; i < goatList.size(); i++)
		{
			goatList[i].SetChildAmount();
			cout << "\nChild of goat " << i + 1 << ": " << goatList[i].GetChildAmount();
			sum += goatList[i].GetLastAmount();
		}
	else
		cout << "\nWrong type\n";
	return sum;
}

int Farm::GetNumberOfMilk()
{
	srand(time(NULL));
	int sum = 0;
	for (int i = 0; i < goatList.size(); i++)
	{
		goatList[i].SetMilkAmount();
		cout << "\nMilk of goat " << i + 1<<": " << goatList[i].GetMilkAmount();
		sum += goatList[i].GetMilkAmount();
	}
	
	for (int i = 0; i < cowList.size(); i++)
	{
		cowList[i].SetMilkAmount();
		cout << "\nMilk of cow " << i + 1 <<": " <<cowList[i].GetMilkAmount();
		sum += cowList[i].GetMilkAmount();
	}
	
	for (int i = 0; i < sheepList.size(); i++)
	{
		sheepList[i].SetMilkAmount();
		cout << "\nMilk of sheep " << i + 1 <<": "<<sheepList[i].GetMilkAmount();
		sum += sheepList[i].GetMilkAmount();
	}
	return sum;
}

void Farm::Sound()
{
	for (int i = 0; i < cowList.size(); i++)
		cowList[i].Sound();
	for (int i = 0; i < goatList.size(); i++)
		goatList[i].Sound();
	for (int i = 0; i < sheepList.size(); i++)
		sheepList[i].Sound();
}

void Farm::Print()
{
	cout << "\n\nNumber of cow after a litter: " << GetNumbersOf("Cow");
	cout << "\nNumber of sheep after a litter: " << GetNumbersOf("Sheep");
	cout << "\nNumber of goat after a litter: " << GetNumbersOf("Goat");
	cout << "\nThe sum of milk liters: " << GetNumberOfMilk();
}