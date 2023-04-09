#include <stdio.h>
#include <limits.h>

#define V 6     // Number of vertices in the graph

// A DFS based function to find if there is a path from source 's' to sink 't' in residual graph
// rGraph: residual graph
// visited: array to store visited vertices
// parent: array to store parent vertices
// s: source vertex
// t: sink vertex
int dfs(int rGraph[V][V], int visited[], int parent[], int s, int t) {
    visited[s] = 1;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && rGraph[s][v] > 0) {
            parent[v] = s;
            if (v == t) {
                return 1;
            }
            if (dfs(rGraph, visited, parent, v, t)) {
                return 1;
            }
        }
    }
    return 0;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;

    // Create a residual graph and fill the residual graph with given capacities in the original graph as
    // residual capacities in residual graph
    int rGraph[V][V];
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];      // This array is filled by DFS and store path

    int max_flow = 0;   // There is no flow initially

    // Augment the flow while there is path from source to sink
    int visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    while (dfs(rGraph, visited, parent, s, t)) {
        // Find minimum residual capacity of the edges along the path filled by DFS
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = path_flow < rGraph[u][v] ? path_flow : rGraph[u][v];
        }

        // Update residual capacities of the edges and reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}

int main() {
    int graph[V][V], s, t, max_flow;

    // Get the input graph
    printf("Enter the graph as an adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Get the source and sink vertices
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    printf("Enter the sink vertex: ");
    scanf("%d", &t);

    max_flow = fordFulkerson(graph, s, t);

    // Print the maximum flow
    printf("Maximum flow is %d", max_flow);
    
    return 0;

}
