#include "../include/menu.h"

int main() {
    int spaceX = 10;
    int spaceY = 5;
    int size = 3;
    Users *(userPtr)[size]{nullptr}; // Array of pointers to Users objects

    initMenu(spaceX, spaceY, userPtr, size);
    return 0;
}