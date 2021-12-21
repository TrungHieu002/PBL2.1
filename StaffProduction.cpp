#include "StaffProduction.h"
StaffProduction::StaffProduction()
{
    this->NumberOfProduce = this->DayOfWork = this->LevelOfSalary = 0;
}
StaffProduction::~StaffProduction()
{
}
void StaffProduction::InputEmployee()
{
    Employee::InputEmployee();
    cout << "\n\t\t\t\tNhap so luong san pham: ";
    cin >> NumberOfProduce;
    do
    {
        cout << "\n\t\t\t\tNhap so ngay lam viec / 1 thang : ";
        cin >> DayOfWork;
    } while (DayOfWork > 31 || NumberOfProduce < 0);
    cout << "\n\t\t\t\tNhap bac luong: ";
    cin >> LevelOfSalary;
}
void StaffProduction::OutputEmployee()
{
    Employee::OutputEmployee();
        // cout << setw(12)  << this->Produce <<"|    "<< setw(6)  << this->Quantily<<"|"<< left << endl;
    cout <<"    "<< setw(7) << this->NumberOfProduce <<"|      "<< setw(8)  << this->DayOfWork <<"|     " << setw(6)<< this->LevelOfSalary<<"|"<< left << endl;
}
void StaffProduction::InputEmployeeFile(ifstream &filein)
{
    Employee::InputEmployeeFile(filein);
    filein >> this->DayOfWork;
    filein.ignore(1);
    filein >> this->NumberOfProduce;
    filein.ignore(1);
    filein >> this->LevelOfSalary;
    filein.ignore(1);
}
void StaffProduction::OutputEmployeeFile(ofstream &fileout)
{
    Employee::OutputEmployeeFile(fileout);
    fileout << this->DayOfWork << ",";
    fileout << this->NumberOfProduce << ",";
    fileout << this->LevelOfSalary;
}