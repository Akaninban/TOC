#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// DFA transition table
int dfa[3][2] = {
    {1, 2}, // State 0, if input is 'a' goes to state 1, if input is 'b' goes to state 2
    {1, 2}, // State 1, if input is 'a' goes to state 1, if input is 'b' goes to state 2
    {1, 2}  // State 2, if input is 'a' goes to state 1, if input is 'b' goes to state 2
};

bool isAccepted(char *str) {
    int currentState = 0,i; // Initial state

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a')
            currentState = dfa[currentState][0];
        else if (str[i] == 'b')
            currentState = dfa[currentState][1];
        else
            return false; // Invalid input character
    }

    return currentState == 1; // Check if the final state is accepting
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isAccepted(str))
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");

    return 0;
}

