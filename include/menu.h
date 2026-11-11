#ifndef MENU_H
#define MENU_H
#include "console.h"

void displayMenu(int x, int y, int selectedIndex, Color color) {
    string options[3] = {"1. New", "2. Display", "3. Logout"};
    printAt(x, y, "=== Application ===", 0, Color::Default);
    for (int i=1; i<=3; i++) {
        printAt(x, y+i*2, options[i-1],  selectedIndex == i, color);
    }
}

void initMenu(int spaceX, int spaceY) {
    int selectedIndex{1};
    while(true) {
        clearScreen();
        displayMenu(spaceX, spaceY, selectedIndex, Color::Red);

        char key = getArrowKey();
        if (key == 'A' && selectedIndex > 1) {
            selectedIndex = (selectedIndex - 1)%4;
        } else if (key == 'B' && selectedIndex < 3) {
            selectedIndex = (selectedIndex + 1)%4;
        }
        clearScreen();
    }
}

#endif