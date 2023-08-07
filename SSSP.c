#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100
struct Edge {
    int dest;
    int weight;
};
struct Graph {
    int numVertices;
    struct Edge* adjList[MAX_VERTICES];
};
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++)
        graph->adjList[i] = NULL;
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = graph->adjList[src];
    graph->adjList[src] = newEdge;
}
int minDistance(int dist[], int visited[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        printf("%d ", vertex);
        return;
    }
    printPath(parent, parent[vertex]);
    printf("%d ", vertex);
}
void printDistances(int dist[], int numVertices, int source) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
void dijkstra(struct Graph* graph, int source) {
    int numVertices = graph->numVertices;
    int dist[numVertices];
    int visited[numVertices];
    int parent[numVertices];
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[source] = 0; 
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, visited, numVertices);
        visited[u] = 1; 
        struct Edge* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->dest;
            int weight = temp->weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }
    printf("Shortest path from vertex %d:\n", source);
    for (int i = 0; i < numVertices; i++) {
        printf("Path to vertex %d: ", i);
        printPath(parent, i);
        printf(" - Distance: %d\n", dist[i]);
    }
}
int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);
)
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 4, 3);
    int source = 0; // Source vertex for SSSP
    dijkstra(graph, source);
    return 0;
}
