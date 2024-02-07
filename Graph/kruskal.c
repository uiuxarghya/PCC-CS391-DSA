#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
  int src, dest, weight;
} Edge;

typedef struct graph
{
  int V, E;
  Edge *edges;
} Graph;

Graph *createGraph(int V, int E)
{
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->V = V;
  graph->E = E;
  graph->edges = (Edge *)malloc(E * sizeof(Edge));
  return graph;
}

int compareEdges(const void *a, const void *b)
{
  return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(int parent[], int i)
{
  if (parent[i] == -1)
    return i;
  return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y)
{
  int xset = find(parent, x);
  int yset = find(parent, y);
  if (xset != yset)
    parent[xset] = yset;
}

void kruskalMST(Graph *graph)
{
  int V = graph->V;
  Edge result[V];
  int e = 0;
  int i = 0;

  qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

  int *parent = (int *)malloc(V * sizeof(int));

  for (i = 0; i < V; i++)
    parent[i] = -1;

  i = 0;

  while (e < V - 1 && i < graph->E)
  {
    Edge next_edge = graph->edges[i++];

    int x = find(parent, next_edge.src);
    int y = find(parent, next_edge.dest);

    if (x != y)
    {
      result[e++] = next_edge;
      unionSets(parent, x, y);
    }
  }

  printf("Edges in the Minimum Spanning Tree:\n");
  for (i = 0; i < e; i++)
  {
    printf("(%d-%d) with weight %d\n", result[i].src, result[i].dest, result[i].weight);
  }

  free(parent);
}

int main()
{
  int V, E;
  printf("Enter the number of vertices: ");
  scanf("%d", &V);
  printf("Enter the number of edges: ");
  scanf("%d", &E);

  Graph *graph = createGraph(V, E);

  for (int i = 0; i < E; i++)
  {
    printf("Enter edge %d (src dest weight): ", i + 1);
    scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
  }

  kruskalMST(graph);

  return 0;
}
