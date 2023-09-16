#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int num;
  struct node *next;
} Node;

int survivor(Node **head, int k)
{
  Node *p, *q;
  int i;

  q = p = *head;
  while (p->next != p)
  {
    for (i = 0; i < k - 1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    printf("%d has been killed.\n", p->num);
    free(p);
    p = q->next;
  }
  *head = p;

  return (p->num);
}

void create(Node **head)
{
  Node *temp, *rear;
  int a, ch;

  do
  {
    printf("Enter a number: ");
    scanf("%d", &a);
    temp = (Node *)malloc(sizeof(Node));
    temp->num = a;
    temp->next = NULL;
    if (*head == NULL)
    {
      *head = temp;
    }
    else
    {
      rear->next = temp;
    }
    rear = temp;
    printf("Do you want to add a number [1/0]? ");
    scanf("%d", &ch);
  } while (ch != 0);
  rear->next = *head;
}

void display(Node *head)
{
  Node *temp;

  temp = head;
  printf("%d   ", temp->num);
  temp = temp->next;
  while (head != temp)
  {
    printf("%d   ", temp->num);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  Node *head = NULL;
  int survive, skip;

  create(&head);
  printf("The persons in circular list are:\n");
  display(head);
  printf("Enter the number of persons to be skipped: ");
  scanf("%d", &skip);
  survive = survivor(&head, skip);
  printf("The person to survive is : %d\n", survive);
  free(head);

  return 0;
}