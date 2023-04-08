#include <stdio.h>
#include <string.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of the longest common subsequence of two strings
int longestCommonSubsequence(char *X, char *Y, int m, int n) {
    // Declare dynamic programming table
    int L[m + 1][n + 1];

    // Fill in dynamic programming table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0; // Set base case
            }
            else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1; // If the last characters match, add 1 to the length of the subsequence
            }
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); // Otherwise, take the maximum of the lengths of the two subsequences obtained by excluding each of the last characters
            }
        }
    }

    // Return the length of the longest common subsequence
    return L[m][n];
}

int main() {
    // Declare variables for input
    char X[100], Y[100];
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    // Call the longest common subsequence algorithm
    int m = strlen(X);
    int n = strlen(Y);
    int length = longestCommonSubsequence(X, Y, m, n);

    // Output the length of the longest common subsequence
    printf("Length of longest common subsequence: %d\n", length);

    return 0;
}
