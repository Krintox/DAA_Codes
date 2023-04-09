#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000 // Maximum number of candidates

// Returns the index of the best candidate in the array of candidates
int hiring(int *candidates, int n) {
    int best = 0; // Initialize the best candidate to be the first candidate
    for (int i = 1; i < n; i++) { // Loop through all candidates starting from the second candidate
        if (candidates[i] > candidates[best]) { // If the current candidate is better than the best candidate so far
            best = i; // Set the current candidate to be the new best candidate
        }
    }
    return best; // Return the index of the best candidate
}

int main() {
    int n; // Number of candidates
    int candidates[MAX_N]; // Array of candidates

    printf("Enter the number of candidates (max %d): ", MAX_N);
    scanf("%d", &n); // Read in the number of candidates from the user

    srand(time(NULL)); // Seed the random number generator with the current time

    // Generate random scores for each candidate and print them out
    for (int i = 0; i < n; i++) {
        candidates[i] = rand() % 101; // Generate a random score
        printf("Candidate %d: %d\n", i+1, candidates[i]);
    }

    int best_candidate = hiring(candidates, n); // Find the index of the best candidate
    printf("The best candidate is %d\n", best_candidate+1); // Print out the index of the best candidate (plus 1 to convert from 0-indexing to 1-indexing)

    return 0; // Return 0 to indicate successful program execution
}
