#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int numVertices, numEdges;
    struct Edge* edges;
};
struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));
    return graph;
}
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return findParent(parent, parent[vertex]);
}
void unionSets(int parent[], int x, int y) {
    int xParent = findParent(parent, x);
    int yParent = findParent(parent, y);
    parent[xParent] = yParent;
}
void kruskalMST(struct Graph* graph) {
    int numVertices = graph->numVertices;
    int numEdges = graph->numEdges;
    struct Edge* edges = graph->edges;
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);
    int* parent = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
        parent[i] = i;
    printf("Minimum Spanning Tree:\n");
    int mstWeight = 0;
    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
        if (findParent(parent, src) != findParent(parent, dest)) {
            printf("%d -- %d  Weight: %d\n", src, dest, weight);
            mstWeight += weight;
            unionSets(parent, src, dest);
        }
    }

    printf("Total Weight of MST: %d\n", mstWeight);
    free(parent);
}
int main() {
    int numVertices = 4;
    int numEdges = 5;
    struct Graph* graph = createGraph(numVertices, numEdges);
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;
    kruskalMST(graph);
    free(graph->edges);
    free(graph);
    return 0;
}
