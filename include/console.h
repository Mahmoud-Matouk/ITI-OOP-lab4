#ifndef CONSOLE_H
#define CONSOLE_H
#include <bits/stdc++.h>
#include <cstdio>
#include <unistd.h>
#include <termios.h>
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

void printAt(int x, int y, const string& text, bool isSelected=false, Color color=Color::Default) {
    goToXY(x, y);
    if (isSelected) setColor(color);
    else setColor(Color::Default);
    cout << text;
    setColor(Color::Default);
    cout << endl;
}

char getch_linux() {
    char buf{};
    struct termios old = {};
    tcgetattr(0, &old);
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &old);
    read(0, &buf, 1);
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    tcsetattr(0, TCSADRAIN, &old);
    return buf;
}

char getArrowKey() {
    char key = getch_linux();

    if (key == '\033') {
        getch_linux();
        return getch_linux();
    }

    return key;
}

// void moveUpDown() {
//     char byte1='q';
//     char byte2='q';
//     char byte3='q';
//     do {
//         byte1= getch_linux();
//         if (byte1 == '\033') {
//             byte2=getch_linux();
//             byte3=getch_linux();
//             switch (byte3) {
//                 case 'A':
//                     printf("↑ Up Arrow\n");
//                     break;

//                 case 'B':
//                     printf("↓ Down Arrow\n");
//                     break;

//                 case 'C':
//                     printf("→ Right Arrow\n");
//                     break;

//                 case 'D':
//                     printf("← Left Arrow\n");
//                     break;
//                 case 'H':
//                     printf("Home Button \n");
//                     break;
//                 case 'F':
//                     printf("End Button\n");
//                     break;
//             }
//         }
//     } while(byte1 != 'q' && byte1 != 'Q'); 
// }

#endif