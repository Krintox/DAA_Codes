#include <stdio.h>
#include <stdbool.h>

// Function to check if subset sum exists for a given sum and set
bool subsetSum(int set[], int n, int sum) {
    // Create a 2D boolean array with n+1 rows and sum+1 columns
    bool subset[n + 1][sum + 1];

    // Initialize the first row as true
    for (int i = 0; i <= sum; i++) {
        subset[0][i] = true;
    }

    // Initialize the first column as false (except for subset[0][0])
    for (int i = 1; i <= n; i++) {
        subset[i][0] = false;
    }

    // Fill the rest of the subset[][] array in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1]) {
                subset[i][j] = subset[i - 1][j];
            }
            else {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }
    }

    // Return subset[n][sum]
    return subset[n][sum];
}

int main() {
    // Declare variables for input
    int n, sum;
    printf("Enter the size of the set: ");
    scanf("%d", &n);
    int set[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d", &sum);

    // Call the subsetSum function and print the result
    if (subsetSum(set, n, sum)) {
        printf("Subset with sum %d exists.\n", sum);
    }
    else {
        printf("Subset with sum %d does not exist.\n", sum);
    }

    return 0;
}
