#include "HoanCauCompany.h"

int main() {
	HoanCauCompany company;
	cout << "----------Staff Manager----------";
	company.Read();
	cout << "\n\n----------Staff Information-----------";
	company.Print();
	cout << "\n\n----------Information of staff with the lower than average salary---------";
	company.LessThanAverageSalary();

	return 0;
}
