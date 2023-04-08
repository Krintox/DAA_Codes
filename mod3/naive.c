#include <stdio.h>
#include <string.h>

void naiveStringMatch(char* text, char* pattern) {
    int textLength = strlen(text);          // Find the length of the text
    int patternLength = strlen(pattern);    // Find the length of the pattern

    for (int i = 0; i <= textLength - patternLength; i++) {    // Loop through the text
        int j;
        for (j = 0; j < patternLength; j++) {    // Loop through the pattern
            if (text[i+j] != pattern[j]) {       // If a mismatch is found, break out of the loop
                break;
            }
        }
        if (j == patternLength) {                // If the entire pattern has been matched, print the index
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "the quick brown fox jumps over the lazy dog";
    char pattern[] = "fox";

    // Find the first occurrence of the pattern in the text using the naive string matching algorithm
    naiveStringMatch(text, pattern);

    return 0;
}
