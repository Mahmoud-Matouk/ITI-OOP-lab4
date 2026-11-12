#include "../include/menu.h"

int main() {
    int spaceX = 10;
    int spaceY = 5;
    int size = 3;
    Users *(userPtr)[size]{nullptr}; // Array of pointers to Users objects

    initMenu(spaceX, spaceY, userPtr, size);

    for (int i = 0; i < size; ++i) {
        userPtr[i] = nullptr;
        delete userPtr[i];
    }
    return 0;
}