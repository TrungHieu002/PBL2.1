#include "StaffManagement.h"
StaffManagement::StaffManagement()
{
    this->ManageDepartment = "";
    this->NumberOfManage = 0;
}
StaffManagement::~StaffManagement()
{
}
void StaffManagement::InputEmployee()
{

    Employee::InputEmployee();
    cout << "\n\t\t\t\tNhap bo phan quan ly: ";
    fflush(stdin);
    getline(cin, ManageDepartment);
    cout << "\n\t\t\t\tNhap so luong nhan vien quan ly: ";
    cin >> NumberOfManage;
}
void StaffManagement::OutputEmployee()
{
    Employee::OutputEmployee();
    cout << setw(11)  << this->ManageDepartment <<"|      "<< setw(7)  << this->NumberOfManage<<"|" << left<< endl;
}
void StaffManagement::InputEmployeeFile(ifstream &filein)
{
    Employee::InputEmployeeFile(filein);
    getline(filein, this->ManageDepartment, ',');
    filein >> this->NumberOfManage;
    filein.ignore(1);
}
void StaffManagement::OutputEmployeeFile(ofstream &fileout)
{
    Employee::OutputEmployeeFile(fileout);
    fileout << this->ManageDepartment << ",";
    fileout << this->NumberOfManage;
}
