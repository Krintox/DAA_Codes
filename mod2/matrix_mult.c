#include <stdio.h>
#include <limits.h>

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the minimum number of multiplications required to multiply a chain of matrices
int matrixChainMultiplication(int p[], int n) {
    // Declare dynamic programming table
    int m[n][n];

    // Set diagonal entries to 0
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // Fill in dynamic programming table
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // Set initial value to infinity
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; // Calculate number of multiplications for this split
                m[i][j] = min(m[i][j], q); // Update minimum number of multiplications if necessary
            }
        }
    }

    // Return the minimum number of multiplications
    return m[1][n - 1];
}

int main() {
    // Declare variables for input
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter the dimensions of the matrices (separated by spaces): ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    // Call the matrix chain multiplication algorithm
    int minMultiplications = matrixChainMultiplication(p, n + 1);

    // Output the minimum number of multiplications
    printf("Minimum number of multiplications: %d", minMultiplications);

    return 0;
}
