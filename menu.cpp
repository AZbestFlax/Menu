#include "menu.h"

// ============ MenuItem =====================
MenuItem::MenuItem(string item, color col) {
    this->item = item;
    this->col = col;
}

// ============ Menu =========================
Menu::Menu(string name, color col) {
    this->col = col;
    this->name = name;
    pos = 0;
    items.clear();
}

void Menu::show() {

    // print border
    clear_screen();
    set_cursor_pos(10,5);
    for (int i=0;i<60;i++) printf("*");

    for (int i=0;i<13;i++) {
        set_cursor_pos(10,5+i);
        printf("*");
        set_cursor_pos(69,5+i);
        printf("*");
    }
    set_cursor_pos(10,18);
    for (int i=0;i<60;i++) printf("*");

    string s = name;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    set_cursor_pos(40-name.length()/2-1, 5);
    cout << " " << s << " ";

    //

    for (int i=0; i<items.size(); i++) {
        set_cursor_pos(14,7+i);
        set_color(DEFAULT_COLOR);
        printf("%2d",i+1);
        set_color(items.at(i).col);
        set_cursor_pos(17,7+i);
        cout << items.at(i).item << endl;
    }


    printCarret();
    printScroll();

    char c = 0;
    do {
        c = getch();
        if (c != 0 && c!= -32) {
            switch(c) {
                case 'w': case 'W': pos--; break;
                case 's': case 'S': pos++; break;
            }
        } else {
            c = getch();
            switch(c) {
                case 72: pos--; break;
                case 80: pos++; break;
            }
        }
        if (pos < 0) pos = items.size()-1;
        if (pos >= items.size()) pos = 0;
        printCarret();
        printScroll();
    } while (c != 13 && c != 27);
    if ( c == 13) {
        printf("%d",pos);
    }
}

void Menu::addItem(string item, color col) {
    MenuItem mi(item, col);
    items.push_back(mi);
}

void Menu::clearItems() {
    items.clear();
}

int Menu::returnChoise() {
    return pos;
}

void Menu::printScroll() {
    for (int i=0;i<10; i++) {
        set_cursor_pos(65,7+i);
        printf("%c",176);
    }

    set_cursor_pos(65,7);
    if (items.size()>10)
        printf("%c",219);
}

void Menu::printCarret() {
    for (int i=0;i<10; i++) {
        set_cursor_pos(12,7+i);
        printf(" ");
    }

    set_color(cWHITE);
    set_cursor_pos(12, 7+pos);
    printf("%c",CARRET);
}
