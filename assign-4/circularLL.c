#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
} Node;

Node *insertFirst(Node *start)
{
  Node *temp, *ptr;
  temp = (Node *)malloc(sizeof(Node));
  printf("Enter a number : ");
  scanf("%d", &temp->data);
  temp->link = NULL;
  if (start == NULL)
  {
    start = temp;
    temp->link = start;
  }
  else
  {
    ptr = start;
    while (ptr->link != start)
      ptr = ptr->link;

    ptr->link = temp;
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
  {
    start = temp;
    temp->link = start;
  }
  else
  {
    ptr = start;
    while (ptr->link != start)
      ptr = ptr->link;

    ptr->link = temp;
    temp->link = start;
  }
  return start;
}

Node *deleteFirst(Node *start)
{
  Node *ptr;
  if (start == NULL)
    printf("\nList is Empty!");
  else
  {
    ptr = start;
    while (ptr->link != start)
      ptr = ptr->link;

    printf("\nDeleted : %d\n", start->data);
    start = start->link;
    ptr->link = start;
  }
  return start;
}

Node *deleteLast(Node *start)
{
  Node *ptr;
  if (start == NULL)
    printf("\nList is Empty!");
  else if (start->link == start)
  {
    printf("\nDeleted : %d\n", start->data);
    start = NULL;
  }
  else
  {
    ptr = start;
    while (ptr->link->link != start)
      ptr = ptr->link;
    printf("\nDeleted : %d\n", ptr->link->data);
    ptr->link = start;
  }
  return start;
}

int count(Node *start)
{
  int c = 0;
  Node *ptr = start;
  while (ptr->link != start)
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
      for (i = 1; i < pos; i++)
        ptr = ptr->link;

      temp->link = ptr->link;
      ptr->link = temp;
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
      for (i = 1; i < pos; i++)
        ptr = ptr->link;

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
    while (ptr->link != start)
    {
      printf("%d->", ptr->data);
      ptr = ptr->link;
    }
    printf("%d->", ptr->data);
  }
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
    printf("\n4. Exit");
    printf("\n\nEnter the choice : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("\n1. Insert First ");
      printf("\n2. Insert Last ");
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
      printf("\n3. Delete from any Position");
      printf("\n\nEnter the choice : ");
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
      exit(1);

    default:
      printf("\nWRONG CHOICE!");
    }
  }
  return 0;
}