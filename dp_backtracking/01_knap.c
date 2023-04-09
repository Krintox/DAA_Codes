#include <stdio.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum value that can be obtained from a 0-1 knapsack problem with n items and capacity W
int knapsack(int W, int wt[], int val[], int n) {
    // Declare dynamic programming table
    int K[n + 1][W + 1];

    // Fill in dynamic programming table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0; // Set base case
            }
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); // If the weight of the current item is less than or equal to the remaining capacity, take the maximum of the values obtained by including and excluding the current item
            }
            else {
                K[i][w] = K[i - 1][w]; // Otherwise, exclude the current item
            }
        }
    }

    // Return the maximum value that can be obtained
    return K[n][W];
}

int main() {
    // Declare variables for input
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    int wt[n], val[n];
    printf("Enter the weights and values of the items (separated by spaces):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }

    // Call the knapsack algorithm
    int maxVal = knapsack(W, wt, val, n);

    // Output the maximum value that can be obtained
    printf("Maximum value that can be obtained: %d\n", maxVal);

    return 0;
}
