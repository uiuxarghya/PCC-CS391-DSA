#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

typedef struct graph
{
  int vertices;
  bool adj[MAX][MAX];
} Graph;

Graph *createGraph(int vertices)
{
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  int i, j;
  for (i = 0; i < vertices; i++)
  {
    for (j = 0; j < vertices; j++)
    {
      g->adj[i][j] = false;
    }
  }
  return g;
}

void addEdge(Graph *g, int src, int dest)
{
  g->adj[src][dest] = true;
}

void BFS(Graph *g, int start)
{
  bool visited[MAX];
  int queue[MAX];
  int i, front = 0, rear = 0;
  for (i = 0; i < g->vertices; i++)
  {
    visited[i] = false;
  }
  visited[start] = true;
  queue[rear++] = start;
  while (front < rear)
  {
    int current = queue[front++];
    printf("%d ", current);
    for (i = 0; i < g->vertices; i++)
    {
      if (g->adj[current][i] == true && visited[i] == false)
      {
        visited[i] = true;
        queue[rear++] = i;
      }
    }
  }
}

int main()
{
  int vertices, edges, i, src, dest, start;

  printf("\nEnter the number of vertices: ");
  scanf("%d", &vertices);
  printf("\nEnter the number of edges: ");
  scanf("%d", &edges);

  Graph *g = createGraph(vertices);

  printf("\n");

  for (i = 0; i < edges; i++)
  {
    printf("Enter the value of edges (src, destination) form: ");
    scanf("%d %d", &src, &dest);
    addEdge(g, src, dest);
  }

  printf("\nEnter the starting vertex: ");
  scanf("%d", &start);

  printf("\nBFS Traversal: ");
  BFS(g, start);

  return 0;
}
