#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <termios.h>
using namespace std;

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



int main() {
    printf("Press the arrow keys to test the program (press 'q' to quit):\n");
    char byte1='q';
    char byte2='q';
    char byte3='q';

    do {
        byte1= getch_linux();
        if (byte1 == '\033') {
            byte2=getch_linux();
            byte3=getch_linux();
            switch (byte3) {
                case 'A':
                    printf("↑ Up Arrow\n");
                    break;

                case 'B':
                    printf("↓ Down Arrow\n");
                    break;

                case 'C':
                    printf("→ Right Arrow\n");
                    break;

                case 'D':
                    printf("← Left Arrow\n");
                    break;
                case 'H':
                    printf("Home Button \n");
                    break;
                case 'F':
                    printf("End Button\n");
                    break;
            }
        }
        cout<<"================================="<<endl;
    } while(byte1 != 'q' && byte1 != 'Q'); 
    return 0;
}
