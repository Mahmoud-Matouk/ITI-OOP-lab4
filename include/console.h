#ifndef CONSOLE_H
#define CONSOLE_H
#include <bits/stdc++.h>
using namespace std;

namespace Ansi {
    inline constexpr char SEP = ';';
    inline constexpr char COLOR_CODE = 'm';
    inline constexpr char CURSOR_POS = 'H';
    inline constexpr string_view CSI = "\033[";
    inline constexpr string_view RESET_COLOR = "\033[0m";
    inline constexpr string_view CLEAR_SCREEN = "\033[2J\033[H";
};

enum class Color {
    Default = 0,
    Red     = 31,
    Green   = 32,
    Yellow  = 33,
    Blue    = 34,
    Magenta = 35,
    Cyan    = 36,
    White   = 37
};

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        cout << Ansi::CLEAR_SCREEN;
    #endif
}

void goToXY(int x, int y) {
    // In ANSI: \033[<line>;<column>H where line is Y (row) and column is X (col)
    cout << Ansi::CSI << y << Ansi::SEP << x << Ansi::CURSOR_POS;
}

void setColor(Color color) {
    if (color == Color::Default)
        cout << Ansi::RESET_COLOR;
    else
        cout << Ansi::CSI << (int)(color) << Ansi::COLOR_CODE;
}

void printAt(int x, int y, const string& text, bool isSelected, Color color) {
    goToXY(x, y);
    if (isSelected) setColor(color);
    else setColor(Color::Default);
    cout << text;
    setColor(Color::Default);
    cout << endl;
}

#endif