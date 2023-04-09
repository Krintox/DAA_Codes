#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define the adjacency matrix for the graph
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Define the number of vertices in the graph
int numVertices;

// Define the array to store the color of each vertex
int color[MAX_VERTICES];

// Function to check if it is safe to color a vertex with the given color
bool isSafe(int v, int c) {
    // Check if any adjacent vertex has the same color
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[v][i] && c == color[i]) {
            return false;
        }
    }
    // If no adjacent vertex has the same color, return true
    return true;
}

// Function to assign colors to all vertices of the graph
bool graphColoringUtil(int v, int numColors) {
    // If all vertices are assigned a color, return true
    if (v == numVertices) {
        return true;
    }
    // Try all possible colors for the current vertex
    for (int c = 1; c <= numColors; c++) {
        // Check if it is safe to color the current vertex with the current color
        if (isSafe(v, c)) {
            color[v] = c;
            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(v + 1, numColors)) {
                return true;
            }
            // If assigning the current color does not lead to a solution, backtrack
            color[v] = 0;
        }
    }
    // If no color can be assigned to the current vertex, return false
    return false;
}

// Function to print the colors assigned to all vertices of the graph
void printColors() {
    printf("Colors assigned to the vertices: ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int main() {
    // Read the number of vertices in the graph
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    // Read the adjacency matrix for the graph
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Initialize the color array to 0
    for (int i = 0; i < numVertices; i++) {
        color[i] = 0;
    }

    // Try to assign colors to all vertices of the graph
    int numColors = 3; // Set the maximum number of colors to 3
    if (graphColoringUtil(0, numColors)) {
        printf("Graph can be colored using %d colors.\n", numColors);
        printColors();
    }
    else {
        printf("Graph cannot be colored using %d colors.\n", numColors);
    }

    return 0;
}
