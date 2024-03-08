#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10
#define MAX_TRANSITIONS 10

// Structure to represent transitions
struct Transition {
    int destination;
    char input;
};

// Structure to represent NFA state
struct State {
    int stateID;
    struct Transition transitions[MAX_TRANSITIONS];
    int numTransitions;
};

// Function prototypes
void findEpsilonClosure(struct State[], int, bool[], int[]);

// Function to find e-closure for a state
void findEpsilonClosureForState(struct State states[], int stateID, bool visited[], int epsilonClosure[]) {
    visited[stateID] = true; // Mark current state as visited
    epsilonClosure[stateID] = 1;
	int i; // Include the state itself in e-closure

    // Iterate over transitions from the current state
    for (i = 0; i < states[stateID].numTransitions; i++) {
        struct Transition transition = states[stateID].transitions[i];
        // If the transition is e and the destination state hasn't been visited yet
        if (transition.input == 'e' && !visited[transition.destination]) {
            // Recursively find e-closure for the destination state
            findEpsilonClosureForState(states, transition.destination, visited, epsilonClosure);
        }
    }
}

// Function to find e-closure for all states
void findEpsilonClosure(struct State states[], int numStates, bool visited[], int epsilonClosure[]) {
    // Initialize visited array
    int i;
    for (i = 0; i < numStates; i++) {
        visited[i] = false;
    }

    // Iterate over all states
    for (i = 0; i < numStates; i++) {
        if (!visited[i]) {
            // If the state hasn't been visited yet, find its e-closure
            findEpsilonClosureForState(states, i, visited, epsilonClosure);
        }
    }
}

int main() {
    // Example NFA with e-moves
    struct State states[MAX_STATES] = {
        {0, {{1, 'e'}, {2, 'e'}}, 2},
        {1, {{3, 'a'}}, 1},
        {2, {{4, 'b'}}, 1},
        {3, {{5, 'e'}}, 1},
        {4, {{6, 'e'}}, 1},
        {5, {{7, 'c'}}, 1},
        {6, {{8, 'd'}}, 1},
        {7, {{9, 'e'}}, 1},
        {8, {{9, 'e'}}, 1},
        {9, {}, 0}
    };

    int numStates = 10;
    bool visited[MAX_STATES];
    int epsilonClosure[MAX_STATES];
    int i,j;

    // Find e-closure for all states
    findEpsilonClosure(states, numStates, visited, epsilonClosure);

    // Print e-closure for each state
    printf("e-closure for each state:\n");
    for ( i = 0; i < numStates; i++) {
        printf("e-closure(%d): ", i);
        for ( j = 0; j < numStates; j++) {
            if (epsilonClosure[j] && j != i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}

