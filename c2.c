#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// DFA transition table
int dfa[3][2] = {
    {1, 2}, // State 0, if input is '0' goes to state 1, if input is '1' goes to state 2
    {-1, 2}, // State 1, if input is '0' goes to state 1, if input is '1' goes to state 2
    {1, 2}  // State 2, if input is '0' goes to state 1, if input is '1' goes to state 2
};

bool isAccepted(char *str) {
    int currentState = 0,i; // Initial state

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0')
            currentState = dfa[currentState][0];
        else if (str[i] == '1')
            currentState = dfa[currentState][1];
        else
            return false; // Invalid input character
        if (currentState == -1) // If transition leads to invalid state, reject
            return false;
    }

    return currentState == 1; // Check if the final state is an accepting state
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

