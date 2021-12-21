#include "StaffSales.h"
StaffSales::StaffSales()
{
    this->Produce = "";
    this->Quantily = 0;
}
StaffSales::~StaffSales()
{
}
void StaffSales::InputEmployee()
{
    Employee::InputEmployee();
    cout << "\n\t\t\t\tNhap mat hang: ";
    fflush(stdin);
    getline(cin, Produce);
    cout << "\n\t\t\t\tNhap so luong: ";
    cin >> Quantily;
}
void StaffSales::OutputEmployee()
{
    Employee::OutputEmployee();
    cout << setw(12)  << this->Produce <<"|    "<< setw(6)  << this->Quantily<<"|"<< left << endl;
}
void StaffSales::InputEmployeeFile(ifstream &filein)
{
    Employee::InputEmployeeFile(filein);
    getline(filein, this->Produce, ',');
    filein >> Quantily;
    filein.ignore(1);
}
void StaffSales::OutputEmployeeFile(ofstream &fileout)
{
    Employee::OutputEmployeeFile(fileout);
    fileout << this->Produce << ",";
    fileout << Quantily;
}