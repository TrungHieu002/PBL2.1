#include "Employee.h"
class StaffTechnical : public Employee
{
private:
    string Major;
    string Degree;

public:
    StaffTechnical();
    ~StaffTechnical();
    void InputEmployee();
    void OutputEmployee();
    void InputEmployeeFile(ifstream &);
    void OutputEmployeeFile(ofstream &);
};