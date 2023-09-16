#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
} Node;

Node *insertFirst(Node *start)
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  printf("Enter a number : ");
  scanf("%d", &temp->data);
  temp->link = NULL;
  if (start == NULL)
    start = temp;
  else
  {
    temp->link = start;
    start = temp;
  }
  return start;
}

Node *insertLast(Node *start)
{
  Node *temp, *ptr;
  temp = (Node *)malloc(sizeof(Node));
  printf("Enter a number : ");
  scanf("%d", &temp->data);
  temp->link = NULL;
  if (start == NULL)
    start = temp;
  else
  {
    ptr = start;
    while (ptr->link != NULL)
      ptr = ptr->link;

    ptr->link = temp;
  }
  return start;
}

Node *deleteFirst(Node *start)
{
  if (start == NULL)
    printf("\nList is Empty!");
  else
  {
    printf("\nDeleted : %d\n", start->data);
    start = start->link;
  }
  return start;
}

Node *deleteLast(Node *start)
{
  Node *ptr;
  if (start == NULL)
    printf("\nList is Empty!");
  else if (start->link == NULL)
  {
    printf("\nDeleted : %d\n", start->data);
    start = NULL;
  }
  else
  {
    ptr = start;
    while (ptr->link->link != NULL)
      ptr = ptr->link;
    printf("\nDeleted : %d\n", ptr->link->data);
    ptr->link = NULL;
  }
  return start;
}

int count(Node *start)
{
  int c = 0;
  Node *ptr = start;
  while (ptr != NULL)
  {
    c++;
    ptr = ptr->link;
  }
  return c;
}

Node *insertAtPos(Node *start)
{
  int pos, nc, i;
  Node *temp, *ptr;
  if (start == NULL)
    printf("\nList Is Empty!");
  else
  {
    printf("\nEnter the Position : ");
    scanf("%d", &pos);
    nc = count(start); // number of nodes
    if (pos >= 1 && pos <= nc)
    {
      temp = (Node *)malloc(sizeof(Node));
      printf("Enter a number : ");
      scanf("%d", &temp->data);
      temp->link = NULL;

      ptr = start;
      for (i = 1; i < pos - 1; i++)
        ptr = ptr->link;

      temp->link = ptr->link;
      ptr->link = temp;

      printf("\nInserted %d at position %d.\n", temp->data, pos);
    }
    else
      printf("\nInvalid Position!");
  }
  return start;
}

Node *deleteAtPos(Node *start)
{
  int pos, nc, i;
  Node *ptr;
  if (start == NULL)
    printf("\nList Is Empty!");
  else
  {
    printf("\nEnter the Position : ");
    scanf("%d", &pos);
    nc = count(start); // number of nodes
    if (pos >= 1 && pos <= nc)
    {

      ptr = start;
      for (i = 1; i < pos - 1; i++)
        ptr = ptr->link;

      printf("\nDeleted : %d\n", ptr->link->data);

      ptr->link = ptr->link->link;
    }
    else
      printf("\nInvalid Position!");
  }
  return start;
}

void display(Node *start)
{
  Node *ptr;
  if (start == NULL)
    printf("\nList is Empty!");
  else
  {
    ptr = start;
    while (ptr != NULL)
    {
      printf("%d->", ptr->data);
      ptr = ptr->link;
    }
  }
}

Node *reverse(Node *start)
{
  Node *prev = NULL;
  Node *current = start;
  Node *next = NULL;

  while (current != NULL)
  {
    next = current->link; // store next
    current->link = prev; // reverse current node's pointer

    // move pointers one position ahead
    prev = current;
    current = next;
  }
  start = prev;
  return start;
}

// sort the linked list using Bubble Sort
Node *sortList(Node *head)
{
  Node *temp1 = head, *temp2;
  while (temp1 != NULL)
  {
    temp2 = head;

    // Finding the largest element in the unsorted part.
    // We put it at the end of the unsorted part.
    while (temp2->link != NULL)
    {
      if (temp2->data > temp2->link->data)
      {
        int temp = temp2->data;
        temp2->data = temp2->link->data;
        temp2->link->data = temp;
      }
      temp2 = temp2->link;
    }
    temp1 = temp1->link;
  }
  return head;
}

int main()
{
  int ch, ch2;
  Node *start = NULL;
  while (1)
  {
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Reverse");
    printf("\n5. Sort");
    printf("\n6. Exit");
    printf("\n\nEnter the choice : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("\n1. Insert First");
      printf("\n2. Insert Last");
      printf("\n3. Insert at any Position");
      printf("\n\nEnter the choice : ");
      scanf("%d", &ch2);

      switch (ch2)
      {
      case 1:
        start = insertFirst(start);
        break;

      case 2:
        start = insertLast(start);
        break;

      case 3:
        start = insertAtPos(start);
        break;

      default:
        printf("WRONG CHOICE!");
      }
      break;

    case 2:
      printf("\n1. Delete First");
      printf("\n2. Delete Last");
      printf("\n3. Delete from any Position ");
      printf("\n\nEnter the choice :");
      scanf("%d", &ch2);

      switch (ch2)
      {
      case 1:
        start = deleteFirst(start);
        break;

      case 2:
        start = deleteLast(start);
        break;

      case 3:
        start = deleteAtPos(start);
        break;

      default:
        printf("\nWRONG CHOICE!");
      }
      break;

    case 3:
      printf("Original List : ");
      display(start);
      printf("\n");
      break;

    case 4:
      start = reverse(start);
      printf("\nReversed List : ");
      display(start);
      break;

    case 5:
      sortList(start);
      printf("\nSorted List : ");
      display(start);
      break;

    case 6:
      exit(1);

    default:
      printf("\nWRONG CHOICE!");
    }
  }
  return 0;
}
