#pragma once
#include "LinkedList.h"
#include "StaffTechnical.h"
#include "StaffManagement.h"
#include "StaffProduction.h"
#include "StaffSales.h"
class Management
{
private:
    LinkedList<Employee *> ListEmployee;

public:
    Management();
    ~Management();
    void ShowEmployee();
    void ShowOption(int);
    void AddEmployee();
    void UpdateEmployee();
    void SearchEmployee();
    void SortEmployee();
    void DeleteEmployee();
    void InputFile();
    void OutputFile();
    int SearchID(const string &);
    void CheckIdandAddEmployee(Employee *, string &, const char &);
    int SearchValue_index(Node<Employee *> *, string (*PointFunc)(), const string &);
    LinkedList<Employee *> *SearchValue(Node<Employee *> *, string (*PointFunc)(Node<Employee *> *), const string &);
    LinkedList<Employee *> *SearchValue(Node<Employee *> *, char (*PointFunc)(Node<Employee *> *), const char &);
};
