#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to simulate the NFA
bool isAccepted(char *str) {
    int currentState = 0,i; // Initial state

    for ( i = 0; str[i] != '\0'; i++) {
        if (currentState == 0 && str[i] == 'o')
            currentState = 1; // Transition from state 0 to state 1 on 'o'
        // Any other transitions are not considered in this simple NFA
    }

    return currentState == 1 && str[strlen(str) - 1] == '1'; // Check if the final state is an accepting state and ends with '1'
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

