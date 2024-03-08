#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool isS(char *);

// Define the CFG rules
bool isS(char *str) {
    if (str[0] == '0' && str[strlen(str) - 1] == '0') {
        // Remove first and last characters from the string
        char newStr[strlen(str) - 1];
        strncpy(newStr, str + 1, strlen(str) - 2);
        newStr[strlen(str) - 2] = '\0';
        return isS(newStr);
    } else if (str[0] == '1' && str[strlen(str) - 1] == '1') {
        // Remove first and last characters from the string
        char newStr[strlen(str) - 1];
        strncpy(newStr, str + 1, strlen(str) - 2);
        newStr[strlen(str) - 2] = '\0';
        return isS(newStr);
    } else if (strlen(str) == 1 && (str[0] == '0' || str[0] == '1')) {
        return true; // Single character '0' or '1'
    } else if (strlen(str) == 0) {
        return true; // Empty string
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

