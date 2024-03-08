#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool isS(char *);
bool isA(char *);

// Define the CFG rules
bool isS(char *str) {
    int len = strlen(str);
    if (len >= 5 && str[0] == '0' && str[len - 4] == '1' && str[len - 3] == '0' && str[len - 2] == '1') {
        // Check if the string has the form A101A
        char newStr[len - 4];
        strncpy(newStr, str + 1, len - 5);
        newStr[len - 5] = '\0';
        return isA(newStr);
    }
    return false;
}

bool isA(char *str) {
    if (str[0] == '0') {
        return isA(str + 1);
    } else if (str[0] == '1') {
        return isA(str + 1);
    } else if (str[0] == '\0') {
        return true; // Empty string is in the language
    }
    return false; // Not part of the language
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isS(str)) {
        printf("String belongs to the language\n");
    } else {
        printf("String does not belong to the language\n");
    }

    return 0;
}

