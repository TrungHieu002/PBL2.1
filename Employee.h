#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Employee
{
protected:
    string Id;
    string Name;
    string DateOfBirth;
    string Address;
    string Gender;
    string Position;

public:
    Employee();
    ~Employee();
    virtual void InputEmployee();
    virtual void OutputEmployee();
    virtual void InputEmployeeFile(ifstream &);
    virtual void OutputEmployeeFile(ofstream &);
    void SetID(string);
    void SetName(string);
    void SetDateOfBirth(string);
    void SetAddress(string);
    void SetPosition(string);
    string GetID();
    string GetName();
    string GetDateOfBirth();
    string GetPosition();
    friend bool operator==(const Employee &, const Employee &);
    friend bool operator==(const Employee &, const string &);
    friend bool operator>(const Employee &, const Employee &);
};
