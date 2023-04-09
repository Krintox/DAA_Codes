#include <stdio.h>
#include <string.h>

void computePrefixFunction(char* pattern, int* prefixFunction, int patternLength) {
    int k = -1;                          // Initialize a counter k
    prefixFunction[0] = k;              // The prefix function of the first character is always -1

    for (int i = 1; i < patternLength; i++) {      // Loop through the pattern
        while (k >= 0 && pattern[k+1] != pattern[i]) {    // If a mismatch is found, backtrack
            k = prefixFunction[k];
        }
        if (pattern[k+1] == pattern[i]) {            // If a match is found, update k
            k++;
        }
        prefixFunction[i] = k;                       // Update the prefix function value for i
    }
}

void KMP(char* text, char* pattern) {
    int textLength = strlen(text);              // Find the length of the text
    int patternLength = strlen(pattern);        // Find the length of the pattern

    int prefixFunction[patternLength];          // Create an array to store the prefix function
    computePrefixFunction(pattern, prefixFunction, patternLength);    // Compute the prefix function of the pattern

    int j = -1;                 // Initialize a counter j
    for (int i = 0; i < textLength; i++) {       // Loop through the text
        while (j >= 0 && pattern[j+1] != text[i]) {      // If a mismatch is found, backtrack
            j = prefixFunction[j];
        }
        if (pattern[j+1] == text[i]) {                  // If a match is found, update j
            j++;
        }
        if (j == patternLength - 1) {                   // If the entire pattern has been matched, print the index
            printf("Pattern found at index %d\n", i - j);
            j = prefixFunction[j];                      // Update j using the prefix function
        }
    }
}

int main() {
    char text[] = "the quick brown fox jumps over the lazy dog";
    char pattern[] = "fox";

    // Find the first occurrence of the pattern in the text using the KMP algorithm
    KMP(text, pattern);

    return 0;
}
