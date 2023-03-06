#include "Officer.h"
#include "ProductionStaff.h"
#include <vector>


int SumOfWage(vector<Officer>, vector <ProductionStaff>);
Staff* MaxWage(vector<Officer>, vector <ProductionStaff>);
int main()
{
	vector<Officer> officerList;
	vector<ProductionStaff> productionStaffList;
	int key = -1;

	do
	{
		do
		{
			cout << "Choose your type of Staff:(1:officer , 2: production staff): ";
			cin >> key;
		} while (key != 0 && key != 1 && key != 2 );
		switch (key)
		{
			case 1:
			{
				Officer officer;
				cin >> officer;
				officer.CalcWage();
				officerList.push_back(officer);
				break;
			}
			case 2:
			{
				ProductionStaff productionStaff;
				cin >> productionStaff;
				productionStaff.CalcWage();
				productionStaffList.push_back(productionStaff);
				break;
			}
			default:
				break;
		}
	}while (key != 0);
	cout << "\n\nList of officer\n";
	for (int i = 0; i < officerList.size(); i++)
		cout << "\nStaff " << i + 1 << ": " << officerList[i];
	cout << "\n\nList of production staff\n";
	for (int i = 0; i < productionStaffList.size(); i++)
		cout << "\nStaff " << i + 1 << ": " << productionStaffList[i];
	cout << "\n\nSum of wage: " << SumOfWage(officerList, productionStaffList);
	cout << "\n\nThe staff has the highest wage is: ";
	MaxWage(officerList, productionStaffList)->Print();
	
}

int SumOfWage(vector<Officer> list1, vector <ProductionStaff> list2)
{
	int wage = 0;
	for (int i = 0; i < list1.size(); i++)
		wage += list1[i].GetWage();
	for (int i = 0; i < list2.size(); i++)
		wage += list2[i].GetWage();
	return wage;
}

Staff* MaxWage(vector<Officer> list1, vector <ProductionStaff> list2)
{
	Staff* max=new Staff;
	
	for (int i = 0; i < list1.size(); i++)
		if (max->GetWage() < list1[i].GetWage())
			max = new Officer(list1[i]);
	for (int i = 0; i < list2.size(); i++)
		if (max->GetWage() < list2[i].GetWage())
			max = new ProductionStaff(list2[i]);
	return max;
}