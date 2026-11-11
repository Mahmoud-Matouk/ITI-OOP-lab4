#ifndef STATICMENU_H
#define STATICMENU_H
#include <iostream>
using namespace std;

class Users {
    private:
        char *name;
        char *password;
        char *email;
        int age;

    public:
        Users(char *username, char *passwd, char *userEmail, int userAge): name(username), password(passwd), email(userEmail), age(userAge) {};
        
        //validate for numbers
        void setName(char *username) {
            while (true) {
                cout << "Enter username: ";
                if (!(cin >> username)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "  Invalid username can't be empty, please try again.\n";
                } else if (isdigit(username[0])) {
                    cout << "  The username can't have numbers. Try again.\n";
                } else {
                    break;
                }
            }
        }

        void setNewUser(char *username, char *passwd, char *userEmail, int userAge) {
            setName(username);
            // cout << "Enter password: ";
            // cin >> passwd;
            // this->password = passwd;

            // cout << "Enter email: ";
            // cin >> userEmail;
            // this->email = userEmail;

            // cout << "Enter age: ";
            // cin >> userAge;
            // this->age = userAge;
        };
};

#endif