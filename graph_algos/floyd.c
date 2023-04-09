#include <stdio.h>
#define INF 99999

void floydWarshall(int graph[][100], int vertices) {
  int dist[vertices][vertices], i, j, k;

  // Initialize the dist array with the values of the input graph
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  // Calculate the shortest distances between all pairs of vertices
  for (k = 0; k < vertices; k++) {
    for (i = 0; i < vertices; i++) {
      for (j = 0; j < vertices; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  // Print the shortest distance matrix
  printf("\nShortest Distance Matrix:\n");
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      if (dist[i][j] == INF) {
        printf("INF\t");
      } else {
        printf("%d\t", dist[i][j]);
      }
    }
    printf("\n");
  }
}

int main() {
  int vertices, graph[100][100], i, j;

  // Take user input for the number of vertices in the graph
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  // Take user input for the adjacency matrix of the graph
  printf("\nEnter the adjacency matrix (Enter '99999' for infinity):\n");
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      scanf("%d", &graph[i][j]);
      if (graph[i][j] == 99999) {
        graph[i][j] = INF;
      }
    }
  }

  // Call the Floyd Warshall function to calculate the shortest distances
  floydWarshall(graph, vertices);

  return 0;
}
