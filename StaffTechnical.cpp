#include "StaffTechnical.h"
StaffTechnical::StaffTechnical()
{
    this->Major = "";
    this->Degree = "";
}
StaffTechnical::~StaffTechnical()
{
}
void StaffTechnical::InputEmployee()
{
    Employee::InputEmployee();
    cout << "\n\t\t\t\tNhap chuyen nganh: ";
    fflush(stdin);
    getline(cin, Major);
    cout << "\n\t\t\t\tNhap trinh do: ";
    fflush(stdin);
    getline(cin, Degree);
}
void StaffTechnical::OutputEmployee()
{
    Employee::OutputEmployee();
    cout<< setw(12) << this->Major <<"|  "<< setw(9) << this->Degree<<"|" << left<< endl;
}
void StaffTechnical::InputEmployeeFile(ifstream &filein)
{
    Employee::InputEmployeeFile(filein);
    getline(filein, this->Major, ',');
    getline(filein, this->Degree, '\n');
}
void StaffTechnical::OutputEmployeeFile(ofstream &fileout)
{
    Employee::OutputEmployeeFile(fileout);
    fileout << this->Major << ",";
    fileout << this->Degree;
}