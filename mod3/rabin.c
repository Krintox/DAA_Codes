#include <stdio.h>
#include <string.h>

#define d 256 // size of the alphabet
#define q 101 // a prime number for hashing

// function to find the occurences of pattern in text using Rabin-Karp algorithm
void search(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0, t = 0; // hash values for pattern and text
    int h = 1;

    // h is the hash value of the highest order character in the pattern
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // calculate the initial hash values for pattern and text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // check for matches
    for (i = 0; i <= N - M; i++) {
        // if the hash values match, check each character
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // calculate the hash value for the next window
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    fgets(text, 100, stdin);
    printf("Enter the pattern to be searched: ");
    fgets(pattern, 100, stdin);

    // remove the newline character from the input strings
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    search(pattern, text);
    return 0;
}
