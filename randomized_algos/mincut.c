#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000

int graph[MAX_VERTICES][MAX_EDGES];
int num_vertices, num_edges;

// Function to contract the edge (u, v) into a single vertex
void contract(int u, int v)
{
    // Merge vertex v into vertex u
    for (int i = 0; i < num_edges; i++) {
        graph[u][i] += graph[v][i];
        graph[v][i] = 0;
    }

    // Remove self-loops
    graph[u][u] = 0;
    for (int i = 0; i < num_vertices; i++) {
        graph[i][u] += graph[i][v];
        graph[i][v] = 0;
    }
}

// Function to find the minimum cut of the graph
int minimum_cut()
{
    // Initialize the cut to be the empty set
    int cut_size = num_vertices - 1;

    // Repeat until there are only 2 vertices left
    while (cut_size > 1) {
        // Choose a random edge (u, v) in the graph
        int u = -1, v = -1;
        while (u == v || graph[u][v] == 0) {
            u = rand() % num_vertices;
            v = rand() % num_vertices;
        }

        // Contract the edge (u, v) into a single vertex
        contract(u, v);

        // Update the cut size
        cut_size--;
    }

    // Count the number of edges that cross the cut
    int cut = 0;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_edges; j++) {
            if (graph[i][j] && j >= num_vertices) {
                cut++;
            }
        }
    }

    return cut;
}

int main()
{
    // Read input from user
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &num_vertices, &num_edges);

    // Initialize the graph
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_edges; j++) {
            graph[i][j] = 0;
        }
    }

    // Read the edges of the graph
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Find the minimum cut of the graph
    int min_cut = minimum_cut();

    // Print the result
    printf("The minimum cut has size %d.\n", min_cut);

    return 0;
}
