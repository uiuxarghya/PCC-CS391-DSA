#include <stdio.h>
#include <stdlib.h>

typedef struct pqueue {
  int *arr;
  int size;
} PriorityQueue;

// Initialize an empty priority queue
void initializeQueue(PriorityQueue *queue, int max_size) {
  queue->size = 0;
  queue->arr = (int *)malloc(max_size * sizeof(int));
}

// Enqueue an element with its priority
void enqueue(PriorityQueue *queue, int element) {
  int i = queue->size - 1;

  while (i >= 0 && element < queue->arr[i]) {
    queue->arr[i + 1] = queue->arr[i];
    i--;
  }

  queue->arr[i + 1] = element;
  queue->size++;
}

// Dequeue the element with the highest priority
int dequeue(PriorityQueue *queue) {
  if (queue->size == 0) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1; // Return a sentinel value for an empty queue
  }

  int dequeuedElement = queue->arr[0];

  for (int i = 1; i < queue->size; i++) {
    queue->arr[i - 1] = queue->arr[i];
  }

  queue->size--;

  return dequeuedElement;
}

// Display the elements in the priority queue
void display(PriorityQueue *queue) {
  if (queue->size == 0) {
    printf("Queue is empty.\n");
    return;
  }

  printf("Priority Queue Contents: ");
  for (int i = 0; i < queue->size; i++) {
    printf("%d ", queue->arr[i]);
  }
  printf("\n");
}

int main() {
  int max_size;
  printf("Enter the maximum size of the priority queue: ");
  scanf("%d", &max_size);

  PriorityQueue queue;
  initializeQueue(&queue, max_size);

  int choice, element;

  while (1) {
    printf("Priority Queue Menu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      if (queue.size < max_size) {
        printf("Enter the element to enqueue: ");
        scanf("%d", &element);
        enqueue(&queue, element);
      } else {
        printf("Queue is full. Cannot enqueue.\n");
      }
      break;
    case 2:
      element = dequeue(&queue);
      if (element != -1) {
        printf("Dequeued: %d\n", element);
      }
      break;
    case 3:
      display(&queue);
      break;
    case 4:
      free(queue.arr); // Free dynamically allocated memory
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
