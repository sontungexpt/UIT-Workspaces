//
// Created by tung on 13/06/2022.
//

#include "HoanCauCompany.h"

HoanCauCompany::HoanCauCompany() {
	numberOfStaffs = 0;
	staffs = nullptr;
}

HoanCauCompany::~HoanCauCompany() {
	if (staffs != nullptr) {
		delete[] staffs;
		staffs = nullptr;
		numberOfStaffs = 0;
	}
}

void HoanCauCompany::Read() {
	do {
		cout << "\nEnter the number of staff: ";
		cin >> numberOfStaffs;
	} while (numberOfStaffs < 0);

	staffs = new Staff * [numberOfStaffs];

	for (int i = 0; i < numberOfStaffs; i++) {
		int key;
		cout << "\n\nStaff " << i + 1 << ":";
		do {
			cout << "\nEnter the type of staff ("
				<< Staff::Type::DEVELOPER << ". Developer, "
				<< Staff::Type::TESTER << ".Tester): ";
			cin >> key;
		} while (key != Staff::Type::DEVELOPER && key != Staff::Type::TESTER);

		switch (key) {
		case Staff::Type::DEVELOPER:
			staffs[i] = new Developer;
			break;
		case Staff::Type::TESTER:
			staffs[i] = new Tester;
			break;
		default:
			break;
		}

		staffs[i]->Read();
	}
}

void HoanCauCompany::Print() {
	for (int i = 0; i < numberOfStaffs; i++) {
		cout << "\n\nStaff " << i + 1 << ":";
		staffs[i]->Print();
	}
}

double HoanCauCompany::AverageSalary() {
	double sum = 0;
	for (int i = 0; i < numberOfStaffs; i++)
		sum += staffs[i]->GetSalary();
	return sum / (double)numberOfStaffs;
}


//print the staffs with the current salary is less than average salary
void HoanCauCompany::LessThanAverageSalary() {
	for (int i = 0; i < numberOfStaffs; i++)
		if (staffs[i]->GetSalary() < AverageSalary()) {
			cout << "\n\nStaff " << i + 1 << ":";
			staffs[i]->Print();
		}
}