#pragma once
#include "Management.h"
class Menu
{
private:
    int Control;

public:
    Menu();
    ~Menu();
    int SelectMenu(int, int);
    void ShowMenu();
    void ProcessMenu();
};