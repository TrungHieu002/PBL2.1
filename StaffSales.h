#include "Employee.h"
class StaffSales : public Employee
{
private:
    string Produce;
    int Quantily;

public:
    StaffSales();
    ~StaffSales();
    void InputEmployee();
    void OutputEmployee();
    void InputEmployeeFile(ifstream &);
    void OutputEmployeeFile(ofstream &);
};