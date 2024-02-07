#include <stdio.h>
#include <stdlib.h>

// Define a structure for a polynomial term
struct Node
{
  int coefficient;
  int exponent;
  struct Node *next;
};

typedef struct Node Node;

// Function to insert a term into a polynomial
void insert(Node **poly, int coeff, int exp)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->coefficient = coeff;
  newNode->exponent = exp;
  newNode->next = NULL;

  if (*poly == NULL)
  {
    *poly = newNode;
  }
  else
  {
    Node *current = *poly;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newNode;
  }
}

// Function to print a polynomial
void print(Node *poly)
{
  Node *current = poly;
  while (current != NULL)
  {
    printf("%dx^%d ", current->coefficient, current->exponent);
    current = current->next;
    if (current != NULL)
    {
      printf("+ ");
    }
  }
  printf("\n");
}

// Function to add two polynomials
Node *add(Node *poly1, Node *poly2)
{
  Node *result = NULL;
  while (poly1 != NULL && poly2 != NULL)
  {
    if (poly1->exponent > poly2->exponent)
    {
      insert(&result, poly1->coefficient, poly1->exponent);
      poly1 = poly1->next;
    }
    else if (poly1->exponent < poly2->exponent)
    {
      insert(&result, poly2->coefficient, poly2->exponent);
      poly2 = poly2->next;
    }
    else
    {
      int sum_coeff = poly1->coefficient + poly2->coefficient;
      if (sum_coeff != 0)
      {
        insert(&result, sum_coeff, poly1->exponent);
      }
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
  }

  // Copy any remaining terms from poly1 and poly2
  while (poly1 != NULL)
  {
    insert(&result, poly1->coefficient, poly1->exponent);
    poly1 = poly1->next;
  }

  while (poly2 != NULL)
  {
    insert(&result, poly2->coefficient, poly2->exponent);
    poly2 = poly2->next;
  }

  return result;
}

int main()
{
  Node *poly1 = NULL;
  Node *poly2 = NULL;

  int coeff, exp;
  int n;

  printf("Enter the number of terms in the first polynomial: ");
  scanf("%d", &n);
  printf("Enter the terms for the first polynomial (coeff exponent):\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &coeff, &exp);
    insert(&poly1, coeff, exp);
  }

  printf("Enter the number of terms in the second polynomial: ");
  scanf("%d", &n);
  printf("Enter the terms for the second polynomial (coeff exponent):\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &coeff, &exp);
    insert(&poly2, coeff, exp);
  }

  printf("First polynomial: ");
  print(poly1);
  printf("Second polynomial: ");
  print(poly2);

  Node *result = add(poly1, poly2);
  printf("Result: ");
  print(result);

  // Free memory allocated for the polynomials
  free(poly1);
  free(poly2);
  free(result);

  return 0;
}
