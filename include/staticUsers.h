#ifndef STATICMENU_H
#define STATICMENU_H
#define MAX_SIZE 100
#include "utils.h"
using namespace std;

class Users {
    private:
        char name[MAX_SIZE];
        char password[MAX_SIZE];
        char email[MAX_SIZE];
        int age;

    public:
        Users() {
            this->name[0] = '\0';
            this->password[0] = '\0';
            this->email[0] = '\0';
            this->age = 0;
        }

        bool setName(char *username) {
            if (username == nullptr) return false;
            int len = strLen(username);
            if (len == 0 || len >= MAX_SIZE) return false;
            for (int i = 0; i < len; ++i) {
                if (isDigit(username[i])) return false;
            }
            strCopy(username, this->name);
            return true;
        }

        bool setPassword(char *passwd) {
            if (passwd == nullptr) return false;
            int len = strLen(passwd);
            if (len <= 6 || len >= MAX_SIZE) return false;
            strCopy(passwd, this->password);
            return true;
        }

        bool isPasswordSet(Users *user, int index) {
            return user->password[index] != '\0';
        }

        bool setEmail(char *userEmail) {
            if (userEmail == nullptr) return false;
            int len = strLen(userEmail);
            if (len == 0 || len >= MAX_SIZE) return false;

            int atPosition = -1;
            int dotPosition = -1;
            for (int i = 0; i < len; i++) {
                if (userEmail[i] == '@') {
                    if (atPosition != -1) return false;
                    atPosition = i;
                }
                if (userEmail[i] == '.') {
                    dotPosition = i;
                }
            }
            if (atPosition <= 0 || dotPosition <= atPosition + 1 || dotPosition >= len - 1) return false;
            strCopy(userEmail, this->email);
            return true;
        }


        bool setAge(int userAge) {
            if (userAge < 1 || userAge > 100) return false;
            this->age = userAge;
            return true;
        }

        const char* getName() {
            return this->name;
        }

        const char* getEmail() {
            return this->email;
        }

        int getAge() {
            return this->age;
        }

        void setNewUser(char *username, char *passwd, char *userEmail, int userAge) {
            setName(username);
            setPassword(passwd);
            setEmail(userEmail);
            setAge(userAge);
        };
};

#endif