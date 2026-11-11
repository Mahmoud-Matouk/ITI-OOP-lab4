#ifndef MENU_H
#define MENU_H
#include "console.h"

void displayMenu(int x, int y, int selectedIndex, Color color) {
    string options[3] = {"1. Settings", "2. Profile", "3. Logout"};
    printAt(x, y, "=== Application ===", 0, Color::Default);
    for (int i=1; i<=3; i++) {
        printAt(x, y+i*2, options[i-1],  selectedIndex == i, color);
    }
}

void initMenu(int spaceX, int spaceY) {
    clearScreen();
    displayMenu(spaceX, spaceY, 1, Color::Red);
}

#endif