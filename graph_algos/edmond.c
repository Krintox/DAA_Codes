#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 100    // maximum number of vertices in the graph

// Returns true if there is a path from source 's' to sink 't' in residual graph.
// Also updates parent[] to store the path.
bool bfs(int graph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue, enqueue source vertex and mark it as visited.
    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;   // source has no parent

    // Standard BFS Loop
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && graph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we can reach the sink vertex in BFS starting from source vertex, then return true
    return visited[t];
}

// Finds the maximum flow in the given graph from source 's' to sink 't' using Edmonds-Karp algorithm.
int maxFlow(int graph[V][V], int s, int t) {
    int u, v;

    // Create a residual graph and fill the residual graph with given capacities in the original graph.
    int residualGraph[V][V];  // Residual graph where residualGraph[i][j] indicates residual capacity of edge from i to j
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];   // Parent array to store path

    int max_flow = 0;  // Initialize max flow

    // Augment the flow while there is path from source to sink.
    while (bfs(residualGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = (path_flow < residualGraph[u][v]) ? path_flow : residualGraph[u][v];
        }

        // Update residual capacities of the edges and reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;
        }

        // Add path flow to overall max flow
        max_flow += path_flow;
    }

    // Return the overall max flow
    return max_flow;
}

// Main function to test the Edmonds-Karp algorithm
int main() {
    int n, s, t;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);
    printf("Enter the sink vertex: ");
    scanf("%d", &t);

    int max_flow = maxFlow(graph, s, t);

    printf("Maximum flow in the graph: %d\n", max_flow);

    return 0;
}