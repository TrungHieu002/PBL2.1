#include "Management.h"
#include "Menu.h"

void ShowListBasicInfomation(LinkedList<Employee *> *);
void ShowListDetailsInfomation(LinkedList<Employee *> *);
void Sort(LinkedList<Employee *> *, bool (*PointFunc)(Node<Employee *> *, Node<Employee *> *));
char GetFirstID(Node<Employee *> *);
string GetID(Node<Employee *> *);
string GetName(Node<Employee *> *);
string GetPosition(Node<Employee *> *);
string GetDateOfBirth(Node<Employee *> *);
string SplitString(string, char);
bool SortAscendingName(Node<Employee *> *, Node<Employee *> *);
bool SortDescendingName(Node<Employee *> *, Node<Employee *> *);
bool SortAscendingDate(Node<Employee *> *, Node<Employee *> *);
bool SortDescendingDate(Node<Employee *> *, Node<Employee *> *);
int SwitchDataType(string);
void FormatShow(char firstID);

Management::Management()
{
}
Management::~Management()
{
}
void Management::ShowOption(int Option)
{
    LinkedList<Employee *> *ListTemp = new LinkedList<Employee *>;
    Node<Employee *> *p = new Node<Employee *>;
    if (Option == 1)
    {
        ListTemp = &ListEmployee;
        ShowListBasicInfomation(ListTemp);
    }
    if (Option == 2)
    {
        ListTemp = this->SearchValue(p, GetFirstID, 'B');
        ShowListDetailsInfomation(ListTemp);
        cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
    }
    if (Option == 3)
    {
        ListTemp = this->SearchValue(p, GetFirstID, 'K');
        ShowListDetailsInfomation(ListTemp);
        cout << "|------------------------------------------------------------------------------------------------------------------------|" << endl;
    }
    if (Option == 4)
    {
        ListTemp = this->SearchValue(p, GetFirstID, 'Q');
        ShowListDetailsInfomation(ListTemp);
        cout << "|-------------------------------------------------------------------------------------------------------------------------|" << endl;
    }
    if (Option == 5)
    {
        ListTemp = this->SearchValue(p, GetFirstID, 'S');
        ShowListDetailsInfomation(ListTemp);
        cout << "|--------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    }
}
void Management::ShowEmployee()
{

    if (ListEmployee.IsEmpty())
        cout << "\n\t\t\t\t\tCHUA CO THONG TIN!!!\n";
    else
    {
        int Select;
        LinkedList<Employee *> *ListTemp = new LinkedList<Employee *>;
        Menu menu;
        do
        {
            cout << "\t\t\t\t\t=====================MENU===================\n";
            cout << "\t\t\t\t\t1. Danh sach tat ca nhan vien trong cong ty\n";
            cout << "\t\t\t\t\t2. Danh sach tat ca nhan vien theo phong ban\n";
            cout << "\t\t\t\t\t3. Danh sach nhan vien ban hang\n";
            cout << "\t\t\t\t\t4. Danh sach nhan vien ki thuat\n";
            cout << "\t\t\t\t\t5. Danh sach nhan vien quan ly\n";
            cout << "\t\t\t\t\t6. Danh sach nhan vien san xuat\n";
            cout << "\t\t\t\t\t0. Quay lai!!!\n";
            cout << "\t\t\t\t\t============================================\n";
            Select = menu.SelectMenu(0, 6);
            switch (Select)
            {
            case 1:
                system("cls");
                ListTemp = &ListEmployee;
                ShowListBasicInfomation(ListTemp);
                cout << "\n\t\t\t\tTong nhan vien cua cong ty: " << ListTemp->Size() << endl;
                break;
            case 2:
                system("cls");
                this->ShowOption(2);
                this->ShowOption(3);
                this->ShowOption(4);
                this->ShowOption(5);
                break;
            case 3:
                system("cls");
                this->ShowOption(2);
                break;
            case 4:
                system("cls");
                this->ShowOption(3);
                break;
            case 5:
                system("cls");
                this->ShowOption(4);
                break;
            case 6:
                system("cls");
                this->ShowOption(5);
                break;
            case 0:
                system("cls");
                break;
            }
        } while (Select != 0);
    }
}
void Management::AddEmployee()
{
    Employee *Emp = new Employee();
    string Id;
    Menu menu;
    int selectContinue, Select;
    do
    {
        system("cls");
        cout << "\t\t\t\t\t=================MENU================\n";
        cout << "\t\t\t\t\t1. Nhap thong tin nhan vien ky thuat\n";
        cout << "\t\t\t\t\t2. Nhap thong tin nhan vien quan ly\n";
        cout << "\t\t\t\t\t3. Nhap thong tin nhan vien ban hang\n";
        cout << "\t\t\t\t\t4. Nhap thong tin nhan vien san xuat\n";
        cout << "\t\t\t\t\t0. Thoat!!!\n";
        cout << "\t\t\t\t\t=====================================\n";
        Select = menu.SelectMenu(0, 4);
        switch (Select)
        {
        case 1:
            do
            {
                system("cls");
                cout << "\n\t\t\t\t1. Nhap thong tin nhan vien ky thuat\n";
                Emp = new StaffTechnical();
                this->CheckIdandAddEmployee(Emp, Id, 'K');
                cout << "\n\t\t\t\t1. Nhap tiep \n\t\t\t\t0. Quay lai!!!\n";
                selectContinue = menu.SelectMenu(0, 1);
            } while (selectContinue == 1);
            break;
        case 2:
            do
            {
                system("cls");
                cout << "\n\t\t\t\t2. Nhap thong tin nhan vien quan ly\n";
                Emp = new StaffManagement();
                this->CheckIdandAddEmployee(Emp, Id, 'Q');
                cout << "\n\t\t\t\t1. Nhap tiep \n\t\t\t\t0. Quay lai!!!\n";
                selectContinue = menu.SelectMenu(0, 1);
            } while (selectContinue == 1);
            break;
        case 3:
            do
            {
                system("cls");
                cout << "\n\t\t\t\t3. Nhap thong tin nhan vien ban hang\n";
                Emp = new StaffSales();
                this->CheckIdandAddEmployee(Emp, Id, 'B');
                cout << "\n\t\t\t\t1. Nhap tiep \n\t\t\t\t0. Quay lai!!!\n";
                selectContinue = menu.SelectMenu(0, 1);
            } while (selectContinue == 1);
            break;
        case 4:
            do
            {
                system("cls");
                cout << "\n\t\t\t\t4. Nhap thong tin nhan vien san xuat\n";
                Emp = new StaffProduction();
                this->CheckIdandAddEmployee(Emp, Id, 'S');
                cout << "\n\t\t\t\t1. Nhap tiep \n\t\t\t\t0. Quay lai!!!\n";
                selectContinue = menu.SelectMenu(0, 1);
            } while (selectContinue == 1);
            break;
        case 0:
            system("cls");
            break;
        }
    } while (Select != 0);
}
void Management::UpdateEmployee()
{
    if (ListEmployee.IsEmpty())
        cout << "\n\t\t\t\t\tCHUA CO THONG TIN!\n";
    else
    {
        string s, Id;
        int Select, index;
        Menu x;
        system("cls");
        cout << "\n\t\t\t\t\tNhap ma nhan vien can cap nhat thong tin: ";
        fflush(stdin);
        getline(cin, Id);
        index = this->SearchID(Id);
        if (index == -1)
            cout << "\n\t\t\t\t\tKhong tim thay nhan vien co ma '" << Id << "'" << endl;
        else
        {
            cout << "\n\t\t\t\t\tThong tin nhan vien co ma '" << Id << "'" << endl;
            FormatShow(Id[0]);
            cout << "|  " << setw(3) << 1 << "|  ";

            ListEmployee[index]->OutputEmployee();
            do
            {
                cout << "\t\t\t\t\t=================MENU================\n";
                cout << "\t\t\t\t\t1. Cap nhat ten nhan vien\n";
                cout << "\t\t\t\t\t2. Cap nhat ngay sinh\n";
                cout << "\t\t\t\t\t3. Cap nhat dia chi\n";
                cout << "\t\t\t\t\t4. Cap nhat chuc vu\n";
                cout << "\t\t\t\t\t5. Cap nhat toan bo thong tin\n";
                cout << "\t\t\t\t\t0. Quay lai!!!\n";
                cout << "\t\t\t\t\t=====================================\n";
                Select = x.SelectMenu(0, 5);
                switch (Select)
                {
                case 1:
                    system("cls");
                    cout << "\n\t\t\t\t\t1. Cap nhat ten nhan vien\n";
                    cout << "\n\t\t\t\t\tNhap ten: ";
                    fflush(stdin);
                    getline(cin, s);
                    ListEmployee[index]->SetName(s);
                    cout << "\n\t\t\t\t\tDa cap nhat thong tin\n";
                    FormatShow(Id[0]);
                    cout << "|  " << setw(3) << 1 << "|  ";
                    ListEmployee[index]->OutputEmployee();
                    break;
                case 2:
                    system("cls");
                    cout << "\n\t\t\t\t\t2. Cap nhat ngay sinh\n";
                    cout << "\n\t\t\t\t\tNhap ngay sinh (dd/mm/yyyy): ";
                    fflush(stdin);
                    getline(cin, s);
                    ListEmployee[index]->SetDateOfBirth(s);
                    cout << "\n\t\t\t\t\tDa cap nhat thong tin\n";
                    FormatShow(Id[0]);
                    cout << "|  " << setw(3) << 1 << "|  ";
                    ListEmployee[index]->OutputEmployee();
                    break;
                case 3:
                    system("cls");
                    cout << "\n\t\t\t\t\t3. Cap nhat dia chi\n";
                    cout << "\n\t\t\t\t\tNhap dia chi: ";
                    fflush(stdin);
                    getline(cin, s);
                    ListEmployee[index]->SetAddress(s);
                    cout << "\n\t\t\t\t\tDa cap nhat thong tin\n";
                    FormatShow(Id[0]);
                    cout << "|  " << setw(3) << 1 << "|  ";
                    ListEmployee[index]->OutputEmployee();
                    break;
                case 4:
                    system("cls");
                    cout << "\n\t\t\t\t\t3. Cap nhat chuc vu\n";
                    cout << "\n\t\t\t\t\tNhap chuc vu: ";
                    fflush(stdin);
                    getline(cin, s);
                    ListEmployee[index]->SetPosition(s);
                    cout << "\n\t\t\t\t\tDa cap nhat thong tin\n";
                    FormatShow(Id[0]);
                    cout << "|  " << setw(3) << 1 << "|  ";
                    ListEmployee[index]->OutputEmployee();
                    break;
                case 5:
                    system("cls");
                    cout << "\n\t\t\t\t\t5. Cap nhat toan bo thong tin\n";
                    ListEmployee[index]->InputEmployee();
                    cout << "\n\t\t\t\t\tDa cap nhat thong tin\n";
                    FormatShow(Id[0]);
                    cout << "|  " << setw(3) << 1 << "|  ";
                    ListEmployee[index]->OutputEmployee();
                    break;
                case 0:
                    system("cls");
                    break;
                }
            } while (Select != 0);
        }
    }
}
void Management::SearchEmployee()
{
    if (ListEmployee.IsEmpty())
        cout << "\n\t\t\t\t\tCHUA CO THONG TIN!" << endl;
    else
    {
        Menu menu;
        string s;
        int Select;
        Node<Employee *> *p = new Node<Employee *>;
        LinkedList<Employee *> *ListTemp = new LinkedList<Employee *>;
        do
        {
            cout << "\t\t\t\t\t=================MENU================\n";
            cout << "\t\t\t\t\t1. Tim kiem theo ma nhan vien\n";
            cout << "\t\t\t\t\t2. Tim kiem theo Ho va ten\n";
            cout << "\t\t\t\t\t3. Tim kiem theo nam sinh\n";
            cout << "\t\t\t\t\t4. Tim kiem thep chuc vu\n";
            cout << "\t\t\t\t\t0. Quay lai!!!\n";
            cout << "\t\t\t\t\t=====================================\n";
            Select = menu.SelectMenu(0, 4);
            switch (Select)
            {
            case 1:
                system("cls");
                cout << "\n\t\t\t\t\tNhap ma nhan vien can tim: ";
                fflush(stdin);
                getline(cin, s);
                ListTemp = this->SearchValue(p, GetID, s);
                if (ListTemp->IsEmpty())
                    cout << "\n\t\t\t\t\tKhong tim thay nhan vien co ma '" << s << "'" << endl;
                else
                {
                    cout << "\n\t\t\t\t\tDa tim thay nhan vien co ma '" << s << "'" << endl;
                    ShowListDetailsInfomation(ListTemp);
                }
                break;
            case 2:
                system("cls");
                cout << "\n\t\t\t\t\tNhap Ho va ten nhan vien can tim: ";
                fflush(stdin);
                getline(cin, s);
                ListTemp = this->SearchValue(p, GetName, s);
                if (ListTemp->IsEmpty())
                    cout << "\n\t\t\t\t\tKhong tim thay nhan vien co ho ten '" << s << "'" << endl;
                else
                {
                    cout << "\n\t\t\t\t\tDa tim thay cac nhan vien co ten '" << s << "'!" << endl;
                    ShowListBasicInfomation(ListTemp);
                }
                break;
            case 3:
                system("cls");
                cout << "\n\t\t\t\t\tNhap Ngay thang nam sinh can tim: ";
                fflush(stdin);
                getline(cin, s);
                ListTemp = this->SearchValue(p, GetDateOfBirth, s);
                if (ListTemp->IsEmpty())
                    cout << "\n\t\t\t\t\tKhong tim thay nhan vien co ngay sinh '" << s << "'" << endl;
                else
                {
                    cout << "\n\t\t\t\t\tDa tim thay nhung nhan vien co ngay sinh '" << s << "'" << endl;
                    ShowListBasicInfomation(ListTemp);
                }
                break;
            case 4:
                system("cls");
                cout << "\n\t\t\t\t\tNhap chuc vu nhan vien can tim: ";
                fflush(stdin);
                getline(cin, s);
                ListTemp = this->SearchValue(p, GetPosition, s);
                if (ListTemp->IsEmpty())
                    cout << "\n\t\t\t\t\tKhong tim thay nhan vien co chuc vu '" << s << "'" << endl;
                else
                {
                    cout << "\n\t\t\t\t\tDa tim thay nhung nhan vien co chuc vu '" << s << "'" << endl;
                    ShowListBasicInfomation(ListTemp);
                }
                break;
            case 0:
                system("cls");
                break;
            }
        } while (Select != 0);
    }
}
void Management::SortEmployee()
{
    if (ListEmployee.IsEmpty())
        cout << "\n\t\t\t\t\tCHUA CO THONG TIN!" << endl;
    else
    {
        Menu menu;
        int Select, selectContinue;
        LinkedList<Employee *> *ListTemp = new LinkedList<Employee *>;
        ListTemp = &ListEmployee;
        Node<Employee *> *p = new Node<Employee *>;
        Node<Employee *> *q = new Node<Employee *>;
        do
        {
            cout << "\n\t\t\t\t=================MENU================\n";
            cout << "\t\t\t\t1. Sap xep theo ten nhan vien\n";
            cout << "\t\t\t\t2. Sap xep theo nam sinh\n";
            cout << "\t\t\t\t0. Quay lai!!!\n";
            cout << "\t\t\t\t=====================================\n";
            Select = menu.SelectMenu(0, 2);
            switch (Select)
            {
            case 1:
                system("cls");
                do
                {
                    cout << "\n\t\t\t\t=================MENU================\n";
                    cout << "\t\t\t\t1. Sap xep chieu xuoi(A->Z)\n";
                    cout << "\t\t\t\t2. Sap xep theo chieu nguoc(Z->A)\n";
                    cout << "\t\t\t\t0. Quay lai!!!\n";
                    cout << "\t\t\t\t=====================================\n";
                    selectContinue = menu.SelectMenu(0, 2);
                    switch (selectContinue)
                    {
                    case 1:
                        system("cls");
                        Sort(ListTemp, SortAscendingName);
                        ShowListBasicInfomation(ListTemp);
                        break;
                    case 2:
                        system("cls");
                        Sort(ListTemp, SortDescendingName);
                        ShowListBasicInfomation(ListTemp);
                        break;
                    case 0:
                        system("cls");
                        break;
                    }
                } while (selectContinue != 0);
                break;
            case 2:
                do
                {
                    cout << "\t\t\t\t\t1. Tang dan\n";
                    cout << "\t\t\t\t\t2. Giam dan\n";
                    cout << "\t\t\t\t\t0. Quay lai!!!\n";
                    selectContinue = menu.SelectMenu(0, 2);
                    switch (selectContinue)
                    {
                    case 1:
                        system("cls");
                        Sort(ListTemp, SortDescendingDate);
                        ShowListBasicInfomation(ListTemp);
                        cout << "\n\t\t\t\t\tDa sap xep thanh cong!" << endl;
                        break;
                    case 2:
                        system("cls");
                        Sort(ListTemp, SortAscendingDate);
                        ShowListBasicInfomation(ListTemp);
                        cout << "\n\t\t\t\t\tDa sap xep thanh cong!" << endl;
                        break;
                    case 0:
                        system("cls");
                        break;
                    }
                } while (selectContinue != 0);
                break;
            case 0:
                system("cls");
                break;
            }
        } while (Select != 0);
    }
}
void Management::DeleteEmployee()
{
    if (this->ListEmployee.IsEmpty())
    {
        cout << "\n\t\t\t\t\tCHUA CO THONG TIN!" << endl;
    }
    else
    {
        string Id;
        int Select, index;
        Menu menu;
        system("cls");
        cout << "\n\t\t\t\tNhap ma nhan vien can xoa: ";
        fflush(stdin);
        getline(cin, Id);
        index = this->SearchID(Id);
        if (index == -1)
            cout << "\n\t\t\t\tKhong tim thay nhan vien co ma '" << Id << "'" << endl;
        else
        {
            cout << "\n\t\t\t\tThong tin nhan vien co ma '" << Id << "'" << endl;
            FormatShow(Id[0]);
            cout << "|  " << setw(3) << 1 << "|  ";
            ListEmployee[index]->OutputEmployee();
            do
            {
                cout << "\n\t\t\t\tBan co chac chan muon xoa nhan vien co ma '" << Id << "' nay!"
                     << "\n\t\t\t\t1.Co\n\t\t\t\t0.Quay lai!\n";
                Select = menu.SelectMenu(0, 1);
                if (Select == 1)
                {
                    ListEmployee.RemoveNode(ListEmployee[index]);
                    system("cls");
                    cout << "\n\t\t\t\t\tDa xoa nhan vien thanh cong!\n";
                    break;
                }
                if (Select == 0)
                {
                    system("cls");
                }
            } while (Select != 0);
        }
    }
}
void Management::InputFile()
{
    ifstream filein;
    Employee *Emp = new Employee();
    string PathInput;
    char firstID;
    string s;
    int count = 0;
    cout << "\t\t\t\t\tNhap ten file : ";
    cin >> PathInput;
    filein.open(PathInput, ios::in);
    if (filein.is_open())
    {
        while (true)
        {
            filein.get(firstID);
            switch (firstID)
            {
            case 'K':
                Emp = new StaffTechnical;
                Emp->InputEmployeeFile(filein);
                s = firstID;
                s.append(Emp->GetID());
                if (this->SearchID(s) == -1)
                {
                    Emp->SetID(s);
                    this->ListEmployee.AddTail(Emp);
                }
                else
                    count++;
                break;
            case 'Q':
                Emp = new StaffManagement;
                Emp->InputEmployeeFile(filein);
                s = firstID;
                s.append(Emp->GetID());
                if (this->SearchID(s) == -1)
                {
                    Emp->SetID(s);
                    this->ListEmployee.AddTail(Emp);
                }
                else
                    count++;
                break;
            case 'S':
                Emp = new StaffProduction;
                Emp->InputEmployeeFile(filein);
                s = firstID;
                s.append(Emp->GetID());
                if (this->SearchID(s) == -1)
                {
                    Emp->SetID(s);
                    this->ListEmployee.AddTail(Emp);
                }
                else
                    count++;
                break;
            case 'B':
                Emp = new StaffSales;
                Emp->InputEmployeeFile(filein);
                s = firstID;
                s.append(Emp->GetID());
                if (this->SearchID(s) == -1)
                {
                    Emp->SetID(s);
                    this->ListEmployee.AddTail(Emp);
                }
                else
                    count++;
                break;
            }
            if (filein.eof() == true)
                break;
        }
        filein.close();
        if (count == 0)
        {
            cout << "\n\t\t\t\t\tDoc file";
            cout << PathInput;
            cout << " thanh cong !\n";
        }
        // cout << "\n\t\t\t\t\tDoc file 'InputEmployee.txt' thanh cong !\n";
        // cout << "\n\t\t\t\t\tDoc file"; cout<<PathInput; cout<<"thanh cong !"\n";
        else
            cout << "\n\t\tDa doc thanh cong nhung thong tin nhan vien hop le, co " << count << " nhan vien trung ma nhan vien\n\t\t\t\tVui long kiem tra lai thong tin!\n";
    }
    else
        cout << "\n\t\t\t\t\tMo file that bai" << endl;
}
void Management::OutputFile()
{

    ofstream fileout;
    Menu menu;
    int Select;
    Node<Employee *> *NodeTemp;
    bool firstOut = true;
    do
    {
        cout << "\t\t\t\t\t=================MENU================\n";
        cout << "\t\t\t\t\t1. Xuat file toan bo thong tin nhan vien\n";
        cout << "\t\t\t\t\t2. Xuat file thong tin nhan vien ky thuat\n";
        cout << "\t\t\t\t\t3. Xuat file thong tin nhan vien quan ly\n";
        cout << "\t\t\t\t\t4. Xuat file thong tin nhan vien ban hang\n";
        cout << "\t\t\t\t\t5. Xuat file thong tin nhan vien san xuat\n";
        cout << "\t\t\t\t\t0. Thoat!!!\n";
        cout << "\t\t\t\t\t=====================================\n";
        Select = menu.SelectMenu(0, 5);
        switch (Select)
        {
        case 1:
            fileout.open("AllStaff.txt", ios::out);
            system("cls");
            for (NodeTemp = this->ListEmployee.getHead(); NodeTemp != nullptr; NodeTemp = NodeTemp->pNext)
            {
                NodeTemp->Data->OutputEmployeeFile(fileout);
                if (NodeTemp->pNext != nullptr)
                {
                    fileout << endl;
                }
            }
            cout << "\n\t\t\t\tDa xuat thong tin toan bo nhan vien vao file 'AllStaff.txt'!\n";
            break;
        case 2:
            fileout.open("StaffTechnical.txt", ios::out);
            system("cls");
            for (NodeTemp = this->ListEmployee.getHead(); NodeTemp != nullptr; NodeTemp = NodeTemp->pNext)
            {

                if (GetFirstID(NodeTemp) == 'K')
                {
                    if (firstOut == false)
                    {
                        fileout << endl;
                        NodeTemp->Data->OutputEmployeeFile(fileout);
                    }
                    else
                    {
                        NodeTemp->Data->OutputEmployeeFile(fileout);
                        firstOut = false;
                    }
                }
            }
            cout << "\n\t\t\tDa xuat thong tin toan bo nhan vien ky thuat vao file 'StaffTechnical.txt'!\n";
            break;
        case 3:
            fileout.open("StaffManagement.txt", ios::out);
            system("cls");
            for (NodeTemp = this->ListEmployee.getHead(); NodeTemp != nullptr; NodeTemp = NodeTemp->pNext)
            {

                if (GetFirstID(NodeTemp) == 'Q')
                {
                    if (firstOut == false)
                    {
                        fileout << endl;
                        NodeTemp->Data->OutputEmployeeFile(fileout);
                    }
                    else
                    {
                        NodeTemp->Data->OutputEmployeeFile(fileout);
                        firstOut = false;
                    }
                }
            }
            cout << "\n\t\t\tDa xuat thong tin toan bo nhan vien quan ly vao file 'StaffManagement.txt'!\n";
            break;
        case 4:
            fileout.open("StaffSales.txt", ios::out);
            system("cls");
            for (NodeTemp = this->ListEmployee.getHead(); NodeTemp != nullptr; NodeTemp = NodeTemp->pNext)
            {

                if (GetFirstID(NodeTemp) == 'B')
                {
                    if (firstOut == false)
                    {
                        fileout << endl;
                        NodeTemp->Data->OutputEmployeeFile(fileout);
                    }
                    else
                    {
                        NodeTemp->Data->OutputEmployeeFile(fileout);
                        firstOut = false;
                    }
                }
            }
            cout << "\n\t\t\tDa xuat thong tin toan bo nhan vien ban hang vao file 'StaffSales.txt'!\n";
            break;
        case 5:
            fileout.open("StaffProduction.txt", ios::out);
            system("cls");
            for (NodeTemp = this->ListEmployee.getHead(); NodeTemp != nullptr; NodeTemp = NodeTemp->pNext)
            {

                if (GetFirstID(NodeTemp) == 'S')
                {
                    if (firstOut == false)
                    {
                        fileout << endl;
                        NodeTemp->Data->OutputEmployeeFile(fileout);
                    }
                    else
                    {
                        NodeTemp->Data->OutputEmployeeFile(fileout);
                        firstOut = false;
                    }
                }
            }
            cout << "\n\t\t\tDa xuat thong tin toan bo nhan vien san xuat vao file 'StaffProduction.txt'!\n";
            break;
        case 0:
            system("cls");
            break;
        }
        fileout.close();
    } while (Select != 0);
}
void Management::CheckIdandAddEmployee(Employee *Emp, string &Id, const char &c)
{
    do
    {
        cout << "\n\t\t\t\tNhap Ma nhan vien: ";
        fflush(stdin);
        getline(cin, Id);
        if (this->SearchID(Id) != -1)
            cout << "\n\t\t\t\tMa nhan vien da ton tai. Vui long nhap lai!" << endl;
        if (Id[0] != c || Id.length() != 5)
            cout << "\n\t\t\t\tMa nhan vien gom 5 ki tu bat dau bang '" << c << "'. Vui long nhap lai!" << endl;
    } while (this->SearchID(Id) != -1 || Id[0] != c || Id.length() != 5);
    Emp->SetID(Id);
    Emp->InputEmployee();
    this->ListEmployee.AddTail(Emp);
}
//tìm 1 giá trị có thể là Id, name, DateofBirth trả về index
int Management::SearchID(const string &Id)
{
    if (ListEmployee.IsEmpty())
        return -1;
    else
    {
        for (int i = 0; i < ListEmployee.Size(); i++)
            if (ListEmployee[i]->GetID() == Id)
                return i;
    }
    return -1;
}
int Management::SearchValue_index(Node<Employee *> *p, string (*PointFunc)(), const string &value)
{
    if (ListEmployee.IsEmpty())
        return -1;
    else
    {
        int countNode = 0;
        for (p = ListEmployee.getHead(); p != nullptr; p = p->pNext)
        {
            if (PointFunc() == value)
                return ++countNode;
        }
    }
    return -1;
}
LinkedList<Employee *> *Management::SearchValue(Node<Employee *> *p, string (*PointFunc)(Node<Employee *> *), const string &value)
{
    LinkedList<Employee *> *ListTemp = new LinkedList<Employee *>;
    for (p = ListEmployee.getHead(); p != nullptr; p = p->pNext)
    {
        if (PointFunc(p) == value)
            ListTemp->AddTail(p->Data);
    }
    return ListTemp;
}
//tìm và trả về một danh sách
LinkedList<Employee *> *Management::SearchValue(Node<Employee *> *p, char (*PointFunc)(Node<Employee *> *), const char &value)
{
    LinkedList<Employee *> *ListTemp = new LinkedList<Employee *>;
    for (p = ListEmployee.getHead(); p != nullptr; p = p->pNext)
    {
        if (PointFunc(p) == value)
            ListTemp->AddTail(p->Data);
    }
    return ListTemp;
}
bool SortAscendingName(Node<Employee *> *p, Node<Employee *> *q)
{
    return SplitString(p->Data->GetName(), ' ') > SplitString(q->Data->GetName(), ' ');
}
bool SortDescendingName(Node<Employee *> *p, Node<Employee *> *q)
{
    return SplitString(p->Data->GetName(), ' ') < SplitString(q->Data->GetName(), ' ');
}
bool SortAscendingDate(Node<Employee *> *p, Node<Employee *> *q)
{
    return SwitchDataType(SplitString(p->Data->GetDateOfBirth(), '/')) > SwitchDataType(SplitString(q->Data->GetDateOfBirth(), '/'));
}
bool SortDescendingDate(Node<Employee *> *p, Node<Employee *> *q)
{
    return SwitchDataType(SplitString(p->Data->GetDateOfBirth(), '/')) < SwitchDataType(SplitString(q->Data->GetDateOfBirth(), '/'));
}
void Sort(LinkedList<Employee *> *ListTemp, bool (*PointFunc)(Node<Employee *> *, Node<Employee *> *))
{
    Node<Employee *> *p;
    Node<Employee *> *q;
    for (p = ListTemp->getHead(); p != ListTemp->getTail(); p = p->pNext)
    {
        for (q = p->pNext; q != nullptr; q = q->pNext)
            if (PointFunc(p, q))
            {
                std::swap(p->Data, q->Data);
            }
    }
}
char GetFirstID(Node<Employee *> *p)
{
    return GetID(p)[0];
}
string GetID(Node<Employee *> *p)
{
    return p->Data->GetID();
}
string GetName(Node<Employee *> *p)
{
    return p->Data->GetName();
}
string GetPosition(Node<Employee *> *p)
{
    return p->Data->GetPosition();
}
string GetDateOfBirth(Node<Employee *> *p)
{
    return p->Data->GetDateOfBirth();
}
string SplitString(string s1, char characterInterrupt)
{

    char *Strings2 = new char[s1.length()];
    int Lengths1 = s1.length() - 1;
    while (s1[Lengths1] != characterInterrupt)
    {
        Lengths1--;
    }
    int Lengths2 = 0;
    for (int j = Lengths1 + 1; j <= s1.length() - 1; j++)
    {
        Strings2[Lengths2] = s1[j];
        Lengths2++;
    }
    Strings2[Lengths2] = '\0';
    return Strings2;
}
int SwitchDataType(string s)
{
    stringstream strnum(s);
    int num = 0;
    strnum >> num;
    return num;
}
void ShowListDetailsInfomation(LinkedList<Employee *> *ListTemp)
{
    Node<Employee *> *p = ListTemp->getHead();
    int countNode = 0;
    FormatShow(p->Data->GetID().front());
    while (p != nullptr)
    {
        cout << "|  " << setw(3) << ++countNode << setw(3) << "|";
        p->Data->OutputEmployee();
        p = p->pNext;
    }
    // cout << "|---------------------------------------------------------------------------------------------|" << endl;
}
void ShowListBasicInfomation(LinkedList<Employee *> *ListTemp)
{
    Node<Employee *> *p = ListTemp->getHead();
    int countNode = 0;
    FormatShow('o');
    while (p != nullptr)
    {
        cout << "|  " << setw(3) << ++countNode << setw(3) << "|";
        p->Data->Employee::OutputEmployee();
        cout << endl;
        p = p->pNext;
    }
    cout << "|---------------------------------------------------------------------------------------------|" << endl;
}
void FormatShow(char firstID)
{
    if (firstID == 'o')
    {
        cout << "_______________________________________________________________________________________________" << endl;
        cout << "|" << char(166) << "                                      DANH SACH NHAN VIEN                                  " << char(166) << "|" << endl;
        cout << "|---------------------------------------------------------------------------------------------|" << endl;
        cout << "| STT |" << setw(6) << right
             << "MANV" << setw(3) << "|" << setw(14) << "HO TEN" << setw(8) << "|" << setw(10) << "NGAY SINH" << setw(3) << "|" << setw(12) << "GIOI TINH |"
             << setw(10) << "DIACHI" << setw(5) << "|" << setw(11) << "CHUC VU" << setw(6) << "|" << left << endl;
        cout << "|---------------------------------------------------------------------------------------------|" << endl;
    }
    if (firstID == 'B')
    {
        cout << "_________________________________________________________________________________________________________________________" << endl;
        cout << "|" << char(166) << "                                                  DANH SACH NHAN VIEN BAN HANG                                       " << char(166) << "|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "| STT |" << setw(6) << right
             << "MANV" << setw(3) << "|" << setw(14) << "HO TEN" << setw(8) << "|" << setw(10) << "NGAY SINH" << setw(3) << "|" << setw(12) << "GIOI TINH |"
             << setw(10) << "DIACHI" << setw(5) << "|" << setw(11) << "CHUC VU" << setw(6) << "|" << setw(11) << "MAT HANG" << setw(4) << "|" << setw(9) << "SO LUONG" << setw(2) << "|" << left << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
    }
    if (firstID == 'K')
    {
        cout << "__________________________________________________________________________________________________________________________" << endl;
        cout << "|" << char(166) << "                                                   DANH SACH NHAN VIEN KY THUAT                                       " << char(166) << "|" << endl;
        cout << "|------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "| STT |" << setw(6) << right
             << "MANV" << setw(3) << "|" << setw(14) << "HO TEN" << setw(8) << "|" << setw(10) << "NGAY SINH" << setw(3) << "|" << setw(12) << "GIOI TINH |"
             << setw(10) << "DIACHI" << setw(5) << "|" << setw(11) << "CHUC VU" << setw(6) << "|" << setw(13) << "CHUYEN NGANH" << setw(2) << "|" << setw(9) << "TRINH DO" << setw(3) << "|" << left << endl;
        cout << "|------------------------------------------------------------------------------------------------------------------------|" << endl;
    }
    if (firstID == 'Q')
    {
        cout << "___________________________________________________________________________________________________________________________" << endl;
        cout << "|" << char(166) << "                                                      DANH SACH NHAN VIEN QUAN LY                                      " << char(166) << "|" << endl;
        cout << "|-------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "| STT |" << setw(6) << right
             << "MANV" << setw(3) << "|" << setw(14) << "HO TEN" << setw(8) << "|" << setw(10) << "NGAY SINH" << setw(3) << "|" << setw(12) << "GIOI TINH |"
             << setw(10) << "DIACHI" << setw(5) << "|" << setw(11) << "CHUC VU" << setw(6) << "|" << setw(12) << "BO PHAN QL" << setw(2) << "|" << setw(12) << "SO LUONG QL" << setw(2) << "|" << left << endl;
        cout << "|-------------------------------------------------------------------------------------------------------------------------|" << endl;
    }
    if (firstID == 'S')
    {
        cout << "________________________________________________________________________________________________________________________________________" << endl;
        cout << "|" << char(166) << "                                                           DANH SACH NHAN VIEN SAN XUAT                                             " << char(166) << "|" << endl;
        cout << "|--------------------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "| STT |" << setw(6) << right
             << "MANV" << setw(3) << "|" << setw(14) << "HO TEN" << setw(8) << "|" << setw(10) << "NGAY SINH" << setw(3) << "|" << setw(12) << "GIOI TINH |"
             << setw(10) << "DIACHI" << setw(5) << "|" << setw(11) << "CHUC VU" << setw(6) << "|" << setw(12) << "SL SAN PHAM" << setw(2) << "|" << setw(13) << "SO NGAY CONG" << setw(2) << "|" << setw(10) << "BAC LUONG" << setw(2) << "|" << left << endl;
        cout << "|--------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    }
}