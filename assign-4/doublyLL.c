#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *prev, *next;
} Node;

Node *insertFirst(Node *start)
{
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  printf("Enter a number : ");
  scanf("%d", &temp->data);

  temp->prev = NULL;
  temp->next = NULL;

  if (start == NULL)
    start = temp;
  else
  {
    temp->next = start;
    start->prev = temp;
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

  temp->prev = NULL;
  temp->next = NULL;

  if (start == NULL)
    start = temp;
  else
  {
    ptr = start;
    while (ptr->next != NULL)
      ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;
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
    start = start->next;
    start->prev = NULL;
  }
  return start;
}

Node *deleteLast(Node *start)
{
  Node *ptr;
  if (start == NULL)
    printf("\nList is Empty!");
  else if (start->next == NULL)
  {
    printf("\nDeleted : %d \n", start->data);
    start = NULL;
  }
  else
  {
    ptr = start;
    while (ptr->next != NULL)
      ptr = ptr->next;
    printf("\nDeleted : %d\n", ptr->data);

    ptr = ptr->prev;
    ptr->next->prev = NULL;
    ptr->next = NULL;
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
    ptr = ptr->next;
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
      temp->prev = NULL;
      temp->next = NULL;

      ptr = start;
      for (i = 1; i < pos - 1; i++)
        ptr = ptr->next;

      temp->next = ptr->next;
      temp->prev = ptr;
      ptr->next->prev = temp;
      ptr->next = temp;

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
    printf("\nList is Empty!");
  else
  {
    printf("\nEnter the Position : ");
    scanf("%d", &pos);
    nc = count(start); // number of nodes
    if (pos >= 1 && pos <= nc)
    {

      ptr = start;
      for (i = 1; i < pos; i++)
        ptr = ptr->next;

      printf("\nDeleted : %d\n", ptr->next->data);

      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
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
      printf("%d<->", ptr->data);
      ptr = ptr->next;
    }
  }
}

Node *reverse(Node *start)
{
  Node *current = start;
  Node *temp = NULL;

  while (current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if (temp != NULL)
    return temp->prev;
}

int main()
{
  int ch, ch2;
  Node *start = NULL;
  while (1)
  {
    printf("\n1. Insert.");
    printf("\n2. Delete.");
    printf("\n3. Display.");
    printf("\n4. Reverse ");
    printf("\n5. Exit");
    printf("\n\nEnter the choice : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("\n1. Insert First ");
      printf("\n2. Insert Last ");
      printf("\n3. Insert at any Position ");
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
      start = reverse(start);
      printf("Reversed List : ");
      display(start);
      break;

    case 5:
      exit(1);

    default:
      printf("\nWRONG CHOICE!");
    }
  }
  return 0;
}
