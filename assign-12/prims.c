#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct graph {
    int V; // Number of vertices
    int** graph; // Adjacency matrix
} Graph;

void printMST(int parent[], int key[], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, key[i]);
    }
}

int findMinKey(int key[], bool mstSet[], int V) {
    int min = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && (min == -1 || key[v] < key[min])) {
            min = v;
        }
    }
    return min;
}

void primMST(Graph* graph) {
    int parent[graph->V];
    int key[graph->V];
    bool mstSet[graph->V];

    for (int i = 0; i < graph->V; i++) {
        key[i] = 10000; // Initialize key with a large value (representing infinity)
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->V - 1; count++) {
        int u = findMinKey(key, mstSet, graph->V);
        mstSet[u] = true;

        for (int v = 0; v < graph->V; v++) {
            if (graph->graph[u][v] && !mstSet[v] && graph->graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->graph[u][v];
            }
        }
    }

    printMST(parent, key, graph->V);
}

int main() {
    Graph graph;
    printf("Enter the number of vertices: ");
    scanf("%d", &graph.V);

    graph.graph = (int**)malloc(graph.V * sizeof(int*));
    for (int i = 0; i < graph.V; i++) {
        graph.graph[i] = (int*)malloc(graph.V * sizeof(int));
    }

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < graph.V; i++) {
        for (int j = 0; j < graph.V; j++) {
            scanf("%d", &graph.graph[i][j]);
        }
    }

    primMST(&graph);

    // Free dynamically allocated memory
    for (int i = 0; i < graph.V; i++) {
        free(graph.graph[i]);
    }
    free(graph.graph);

    return 0;
}
