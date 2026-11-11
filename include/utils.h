#ifndef UTILS_H
#define UTILS_H

int strLen(const char* str) {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

char* strCopy(char *str, char *output){
    char *outputStart = output;
    while (*str != '\0') {
        *output = *str;
        str++;
        output++;
    }
    *output = '\0';
    return outputStart;
};

#endif