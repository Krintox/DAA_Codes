#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array using a random pivot
int partition(int arr[], int low, int high) {
    // Generate a random index between low and high inclusive
    int random_index = low + rand() % (high - low + 1);
    int pivot = arr[random_index];
    swap(&arr[random_index], &arr[high]); // Move pivot to the end
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Main function for testing
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL)); // Seed the random number generator
    quicksort(arr, 0, n - 1); // Sort the array using quicksort

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
