#include <stdio.h>
#include <ctype.h>

int calculate(char* s) {
    long long totalResult = 0;
    long long lastTerm = 0;
    long long num = 0;
    char op = '+';

    for (int i = 0; ; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || c == '\0') {
            if (op == '+') {
                totalResult += lastTerm;
                lastTerm = num;
            } else if (op == '-') {
                totalResult += lastTerm;
                lastTerm = -num;
            } else if (op == '*') {
                lastTerm = lastTerm * num;
            } else if (op == '/') {
                lastTerm = lastTerm / num;
            }

            if (c == '\0') break;
            op = c;
            num = 0;
        }
    }

    return (int)(totalResult + lastTerm);
}
