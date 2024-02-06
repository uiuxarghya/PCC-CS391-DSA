#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
typedef struct queue {
  int items[100];
  int front;
  int rear;
} Queue;

// Structure to represent a graph
typedef struct graph
{
  int vertices;
  int **adjMatrix;
} Graph;

// Function to create a new queue
Queue *createQueue()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
  return (queue->front == -1);
}

// Function to enqueue an item
void enqueue(Queue *queue, int value)
{
  if (queue->rear == 99)
  {
    printf("Queue is full\n");
  }
  else
  {
    if (queue->front == -1)
    {
      queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
  }
}

// Function to dequeue an item
int dequeue(Queue *queue)
{
  int item;
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
    item = -1;
  }
  else
  {
    item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
    {
      queue->front = queue->rear = -1;
    }
  }
  return item;
}

// Function to create a new graph
Graph *createGraph(int vertices)
{
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->vertices = vertices;

  graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
  for (int i = 0; i < vertices; i++)
  {
    graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    for (int j = 0; j < vertices; j++)
    {
      graph->adjMatrix[i][j] = 0;
    }
  }

  return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest)
{
  graph->adjMatrix[src][dest] = 1;
  graph->adjMatrix[dest][src] = 1;
}

// Function to perform BFS on the graph
void bfs(Graph *graph, int startVertex)
{
  int visited[100];
  for (int i = 0; i < 100; i++)
  {
    visited[i] = 0;
  }

  Queue *queue = createQueue();

  visited[startVertex] = 1;
  printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

  printf("%d ", startVertex);
  enqueue(queue, startVertex);

  while (!isEmpty(queue))
  {
    int currentVertex = dequeue(queue);

    for (int i = 0; i < graph->vertices; i++)
    {
      if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i])
      {
        printf("%d ", i);
        visited[i] = 1;
        enqueue(queue, i);
      }
    }
  }

  printf("\n");
}

int main()
{
  int vertices, edges;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  Graph *graph = createGraph(vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++)
  {
    int src, dest;
    printf("Enter edge %d (src dest): ", i + 1);
    scanf("%d %d", &src, &dest);
    addEdge(graph, src, dest);
  }

  int startVertex;
  printf("Enter the starting vertex: ");
  scanf("%d", &startVertex);

  bfs(graph, startVertex);

  return 0;
}
