#include <stdio.h>

char firstRepeatedChar(char str[]) {
    int freq[26] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        int index = str[i] - 'a';

        if (freq[index] == 1) {
            return str[i];
        }

        freq[index]++;
    }

    return '-';
}

int main() {
    char str[100];
    
    scanf("%s", str);

    char result = firstRepeatedChar(str);

    if (result == '-')
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}
