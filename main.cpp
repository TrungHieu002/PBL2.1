#include "Menu.h"

int main()
{
    system("cls");
    cout << "\t __________________________________TRUONG DAI HOC BACH KHOA-DAI HOC DA NANG_____________________________";
    cout << "\n\t*" << setw(69) << "<===KHOA CONG NGHE THONG TIN==>" << setw(35) << "*";
    cout << "\n\t*" << setw(104) << "*";
    cout << "\n\t*" << setw(67) << "PBL2: DO AN CO SO LAP TRINH" << setw(37) << "*";
    cout << "\n\t*" << setw(73) << "XAY DUNG HE THONG QUAN LY NHAN LUC CONG TY" << setw(31) << "*";
    cout << "\n\t*" << setw(104) << "*";
    cout << "\n\t*\t Phuong Phap Thuc Hien: SINGLE LINKED LIST & OOP" << setw(42) << "GV Huong Dan: ThS Mai Van Ha\t\t*";
    cout << "\n\t*\t Sv Thuc Hien:" << setw(65) << "So The Sinh Vien" << setw(18) << "*";
    cout << "\n\t*\t Sv1: Le Van Hao" << setw(60) << "102200046" << setw(21) << "*";
    cout << "\n\t*\t Sv2: Tran Trung Hieu" << setw(55) << "102200047" << setw(21) << "*";
    cout << "\n\t*" << setw(104) << "*";
    cout << "\n\t*_______________________________________________________________________________________________________*\n";
    Menu menu;
    menu.ProcessMenu();
    return 0;
}