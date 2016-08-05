#include <iostream>
#include "menu.h"
#include "msoftcon.h"

using namespace std;

int main()
{
    init_graphics();

    Menu m("User");
    m.addItem("Item 1");
    m.addItem("Item 2");
    m.addItem("Item 3");
    m.addItem("Item 4");
    m.addItem("Item 5");
    m.addItem("Item 6");
    m.addItem("Item 7");
    m.addItem("Item 8");
    m.addItem("Item 9");
    m.addItem("Item 10");
    m.show();
    getch();
    return 0;
}
