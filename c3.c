#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool isS(char *);
bool isA(char *);

// Define the CFG rules
bool isS(char *str) {
    if (str[0] == '0' && isA(str + 1)) {
        if (str[1] == '1' && str[2] == '\0') {
            return true;
        }
    }
    return false;
}

bool isA(char *str) {
    if (str[0] == '0' && isA(str + 1)) {
        return true;
    } else if (str[0] == '1' && isA(str + 1)) {
        return true;
    } else if (str[0] == '\0') {
        return true;
    }
    return false;
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

