#include "Employee.h"
class StaffManagement : public Employee
{
private:
    string ManageDepartment;
    int NumberOfManage;

public:
    StaffManagement();
    ~StaffManagement();
    void InputEmployee();
    void OutputEmployee();
    void InputEmployeeFile(ifstream &);
    void OutputEmployeeFile(ofstream &);
};
