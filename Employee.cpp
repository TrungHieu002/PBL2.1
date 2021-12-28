#include "Employee.h"
Employee::Employee()
{
    this->Id = "";
    this->Name = "";
    this->DateOfBirth = "";
    this->Address = "";
    this->Gender = "";
    this->Position = "";
}
Employee::~Employee()
{
}
void Employee::InputEmployee()
{
    cout << "\n\t\t\t\tNhap Ho va ten: ";
    fflush(stdin);
    getline(cin, this->Name);
    cout << "\n\t\t\t\tNhap Ngay sinh (dd/mm/yyyy): ";
    fflush(stdin);
    getline(cin, this->DateOfBirth);
    cout << "\n\t\t\t\tNhap gioi tinh: ";
    fflush(stdin);
    getline(cin, this->Gender);
    cout << "\n\t\t\t\tNhap dia chi: ";
    fflush(stdin);
    getline(cin, this->Address);
    cout << "\n\t\t\t\tNhap chuc vu: ";
    fflush(stdin);
    getline(cin, this->Position);
}
// hieu
void Employee::OutputEmployee()
{
    cout << setw(6) << left << this->Id << setw(2) << "|" << setw(20) << this->Name << "| " << setw(11) << this->DateOfBirth << "|    " << left << setw(7) << this->Gender
         << "|  " << setw(12) << this->Address << "|  " << setw(14) << this->Position << "|  ";
}
void Employee::InputEmployeeFile(ifstream &filein)
{
    getline(filein, this->Id, ',');
    getline(filein, this->Name, ',');
    getline(filein, this->DateOfBirth, ',');
    getline(filein, this->Gender, ',');
    getline(filein, this->Address, ',');
    getline(filein, this->Position, ',');
}
void Employee::OutputEmployeeFile(ofstream &fileout)
{
    fileout << this->Id << ",";
    fileout << this->Name << ",";
    fileout << this->DateOfBirth << ",";
    fileout << this->Gender << ",";
    fileout << this->Address << ",";
    fileout << this->Position << ",";
}
string Employee::GetID()
{
    return this->Id;
}
string Employee::GetName()
{
    return this->Name;
}
string Employee::GetPosition()
{
    return this->Position;
}
string Employee::GetDateOfBirth()
{
    return this->DateOfBirth;
}
void Employee::SetID(string s)
{
    this->Id = s;
}
void Employee::SetName(string s)
{
    this->Name = s;
}
void Employee::SetDateOfBirth(string s)
{
    this->DateOfBirth = s;
}
void Employee::SetAddress(string s)
{
    this->Address = s;
}
void Employee::SetPosition(string s)
{
    this->Position = s;
}
bool operator==(const Employee &Emp1, const Employee &Emp2)
{
    return (Emp1.Id == Emp2.Id ? true : false);
}
bool operator==(const Employee &Emp1, const string &s)
{
    return (Emp1.Id == s ? true : false);
}
bool operator>(const Employee &Emp1, const Employee &Emp2)
{
    return (Emp1.Id > Emp2.Id);
}