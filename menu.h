#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "msoftcon.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct MenuItem {
    string item;
    color col;
    MenuItem(string, color);
};

class Menu {
private:
    static const color DEFAULT_COLOR = cDARK_GRAY;
    static const char CARRET = '>';
    string name;
    vector<MenuItem> items;
    int pos;
    color col;
    void printScroll();
    void printCarret();
public:
    Menu(string, color = DEFAULT_COLOR);
    void show();
    void addItem(string, color = DEFAULT_COLOR);
    void clearItems();
    int returnChoise();
};

#endif // MENU_H_INCLUDED
