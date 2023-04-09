#include <stdio.h>

// Function to find the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the minimum time to complete the assembly
int assemblyLineScheduling(int a[][4], int t[][3], int e[], int x[]) {
    int f1[4], f2[4];
    f1[0] = e[0] + a[0][0]; // Time taken to leave the first station in line 1
    f2[0] = e[1] + a[1][0]; // Time taken to leave the first station in line 2

    // Fill in the dynamic programming tables f1[] and f2[]
    for (int j = 1; j < 4; j++) {
        f1[j] = min(f1[j - 1] + a[0][j], f2[j - 1] + t[1][j - 1] + a[0][j]);
        f2[j] = min(f2[j - 1] + a[1][j], f1[j - 1] + t[0][j - 1] + a[1][j]);
    }

    // Return the minimum time taken to leave the last station
    return min(f1[3] + x[0], f2[3] + x[1]);
}

int main() {
    // Declare variables for input
    int a[2][4], t[2][3], e[2], x[2];

    // Prompt user for input
    printf("Enter the processing times at each station for line 1 (separated by spaces): ");
    scanf("%d %d %d %d", &a[0][0], &a[0][1], &a[0][2], &a[0][3]);
    printf("Enter the processing times at each station for line 2 (separated by spaces): ");
    scanf("%d %d %d %d", &a[1][0], &a[1][1], &a[1][2], &a[1][3]);
    printf("Enter the transfer times between stations for line 1 (separated by spaces): ");
    scanf("%d %d %d", &t[0][0], &t[0][1], &t[0][2]);
    printf("Enter the transfer times between stations for line 2 (separated by spaces): ");
    scanf("%d %d %d", &t[1][0], &t[1][1], &t[1][2]);
    printf("Enter the entry times for each line (separated by spaces): ");
    scanf("%d %d", &e[0], &e[1]);
    printf("Enter the exit times for each line (separated by spaces): ");
    scanf("%d %d", &x[0], &x[1]);

    // Call the assembly line scheduling algorithm
    int minTime = assemblyLineScheduling(a, t, e, x);

    // Output the minimum time
    printf("Minimum time to complete the assembly: %d", minTime);

    return 0;
}
