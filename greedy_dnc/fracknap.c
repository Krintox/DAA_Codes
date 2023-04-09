#include <stdio.h>
#include <stdlib.h>

// Item structure to store the properties of each item
struct item {
    int value;
    int weight;
};

// Function to compare two items based on their value per unit weight
int compare(const void* a, const void* b) {
    struct item* item1 = (struct item*)a;
    struct item* item2 = (struct item*)b;
    double valuePerWeight1 = (double)item1->value / item1->weight;
    double valuePerWeight2 = (double)item2->value / item2->weight;
    if (valuePerWeight1 < valuePerWeight2)
        return 1; // item2 comes first
    else if (valuePerWeight1 > valuePerWeight2)
        return -1; // item1 comes first
    else
        return 0;
}

// Function to perform fractional knapsack algorithm
double fractionalKnapsack(int W, struct item items[], int n) {
    // Sort items based on their value per unit weight
    qsort(items, n, sizeof(items[0]), compare);

    int i;
    double totalValue = 0.0;
    for (i = 0; i < n; i++) {
        // If the item can be added fully, add it and update the remaining weight
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        }
        // If the item can only be added partially, add the fractional part and break
        else {
            double fraction = (double)W / items[i].weight;
            totalValue += fraction * items[i].value;
            break;
        }
    }
    return totalValue;
}

// Driver function to test the fractional knapsack algorithm
int main() {
    int W; // Maximum weight the knapsack can carry
    printf("Enter the maximum weight the knapsack can carry: ");
    scanf("%d", &W);

    int n; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct item items[n]; // Value and weight of each item
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    double maxValue = fractionalKnapsack(W, items, n); // Compute the maximum value
    printf("The maximum value that can be put in the knapsack is: %lf\n", maxValue);

    return 0;
}
