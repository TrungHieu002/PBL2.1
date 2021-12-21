#include "Menu.h"
Menu::Menu()
{
}
Menu::~Menu()
{
}
void Menu::ShowMenu()
{

    cout << setw(70) << left << "\t\t\t\t\t=================MENU================" << endl;
    cout << setw(70) << left << "\t\t\t\t\t1. Them nhan vien" << endl;
    cout << setw(70) << left << "\t\t\t\t\t2. Doc du lieu tu file" << endl;
    cout << setw(70) << left << "\t\t\t\t\t3. Hien thi danh sach nhan vien" << endl;
    cout << setw(70) << left << "\t\t\t\t\t4. Cap nhat thong tin nhan vien" << endl;
    cout << setw(70) << left << "\t\t\t\t\t5. Tim kiem nhan vien" << endl;
    cout << setw(70) << left << "\t\t\t\t\t6. Sap xep nhan vien" << endl;
    cout << setw(70) << left << "\t\t\t\t\t7. Xoa 1 nhan vien" << endl;
    cout << setw(70) << left << "\t\t\t\t\t8. Xuat file thong tin nhan vien" << endl;
    cout << setw(70) << left << "\t\t\t\t\t0. Thoat!!!" << endl;
    cout << setw(70) << left << "\t\t\t\t\t=====================================" << endl;
}
int Menu::SelectMenu(int Exit, int Choose)
{
    this->Control = 0;
    cout << "\n\t\t\t\t\tMoi ban chon : ";
    cin >> Control;
    if (Control >= Exit && Control <= Choose)
        return Control;
    else
        return SelectMenu(Exit, Choose);
}
void Menu::ProcessMenu()
{
    int Select;
    Management management;
    while (true)
    {
        ShowMenu();
        Select = this->SelectMenu(0, 8);
        switch (Select)
        {
        case 1:
            system("cls");
            management.AddEmployee();
            break;
        case 2:
            system("cls");
            management.InputFile();
            break;
        case 3:
            system("cls");
            management.ShowEmployee();
            break;
        case 4:
            system("cls");
            management.UpdateEmployee();
            break;
        case 5:
            system("cls");
            management.SearchEmployee();
            break;
        case 6:
            system("cls");
            management.SortEmployee();
            break;
        case 7:
            system("cls");
            management.DeleteEmployee();
            break;
        case 8:
            system("cls");
            management.OutputFile();
            break;
        case 0:
            cout << "\t\t\t\t\t0.Da Thoat!!!\n";
            exit(1);
            break;
        }
    }
}