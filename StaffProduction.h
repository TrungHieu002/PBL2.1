#include "Employee.h"
class StaffProduction : public Employee
{
protected:
    int DayOfWork;
    int NumberOfProduce;
    int LevelOfSalary;

public:
    StaffProduction();
    ~StaffProduction();
    void InputEmployee();
    void OutputEmployee();
    void InputEmployeeFile(ifstream &);
    void OutputEmployeeFile(ofstream &);
};