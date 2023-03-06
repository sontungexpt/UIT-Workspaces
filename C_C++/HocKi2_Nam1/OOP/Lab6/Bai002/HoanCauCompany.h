//
// Created by tung on 13/06/2022.
//

#ifndef LAB6_2_HOANCAUCOMPANY_H
#define LAB6_2_HOANCAUCOMPANY_H

#include "Tester.h"
#include "Developer.h"

class HoanCauCompany {
private:

    Staff **staffs;
    int numberOfStaffs;


public:

    HoanCauCompany();

    ~HoanCauCompany();

    void Read();

    void Print();

    //print the staffs with the current salary is less than average salary
    void LessThanAverageSalary();

    double AverageSalary();

};


#endif //LAB6_2_HOANCAUCOMPANY_H
