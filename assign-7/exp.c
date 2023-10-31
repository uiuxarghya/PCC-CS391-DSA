#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// The TreeNode struct represents a node in a binary tree, with a character data value and pointers to its left and right child nodes.
typedef struct TreeNode
{
  char data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

// The function creates a new TreeNode with the given data and returns a pointer to it.
TreeNode *createNode(char data)
{
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// The function checks if a character is an operator (+, -, *, /).
bool isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

// The function returns the precedence level of a given operator.
int precedence(char operator)
{
  switch (operator)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  }
  return 0;
}

// The function isALNum checks if a character is alphanumeric.
bool isALNum(char c)
{
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

// The function converts an infix expression to postfix notation using a stack.
void infixToPostfix(char infix[], char postfix[])
{
  char stack[100];
  int top = -1;
  int j = 0;

  for (int i = 0; infix[i]; i++)
  {
    char c = infix[i];
    if (isALNum(c))
    {
      postfix[j++] = c;
    }
    else if (isOperator(c))
    {
      while (top >= 0 && precedence(stack[top]) >= precedence(c))
      {
        postfix[j++] = stack[top--];
      }
      stack[++top] = c;
    }
    else if (c == '(')
    {
      stack[++top] = c;
    }
    else if (c == ')')
    {
      while (top >= 0 && stack[top] != '(')
      {
        postfix[j++] = stack[top--];
      }
      top--; // Remove the '(' from the stack
    }
  }

  while (top >= 0)
  {
    postfix[j++] = stack[top--];
  }

  postfix[j] = '\0';
}

// The function builds an expression tree from a postfix expression.
TreeNode *buildExpressionTree(char postfix[])
{
  TreeNode *stack[100];
  int top = -1;

  for (int i = 0; postfix[i]; i++)
  {
    if (isALNum(postfix[i]))
    {
      stack[++top] = createNode(postfix[i]);
    }
    else if (isOperator(postfix[i]))
    {
      TreeNode *rightOperand = stack[top--];
      TreeNode *leftOperand = stack[top--];

      TreeNode *operatorNode = createNode(postfix[i]);
      operatorNode->left = leftOperand;
      operatorNode->right = rightOperand;

      stack[++top] = operatorNode;
    }
  }

  return stack[top];
}

// The function performs an inorder traversal of a binary tree and prints the data of each node.
void inorderTraversal(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }

  inorderTraversal(root->left);
  printf("%c ", root->data);
  inorderTraversal(root->right);
}

// The function performs a preorder traversal of a binary tree and prints the data of each node.
void preorderTraversal(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }

  printf("%c ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// The function performs a postorder traversal of a binary tree and prints the data of each node.
void postorderTraversal(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%c ", root->data);
}

// The function recursively frees the memory allocated for an expression tree.
void freeExpressionTree(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }
  freeExpressionTree(root->left);
  freeExpressionTree(root->right);
  free(root);
}

int main()
{
  char infix[100];       // User-input infix expression
  char postfix[100];     // Postfix expression
  TreeNode *root = NULL; // Initialize root as NULL

  while (1)
  {
    printf("Menu:\n");
    printf("1. Create Expression Tree\n");
    printf("2. Inorder traversal\n");
    printf("3. Preorder traversal\n");
    printf("4. Postorder traversal\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter infix expression: ");
      scanf("%s", infix);
      infixToPostfix(infix, postfix);
      root = buildExpressionTree(postfix);
      printf("Expression tree built from postfix: %s\n", postfix);
      break;
    case 2:
      if (root == NULL)
      {
        printf("Expression tree not built yet.\n");
      }
      else
      {
        printf("Inorder traversal: ");
        inorderTraversal(root);
        printf("\n");
      }
      break;
    case 3:
      if (root == NULL)
      {
        printf("Expression tree not built yet.\n");
      }
      else
      {
        printf("Preorder traversal: ");
        preorderTraversal(root);
        printf("\n");
      }
      break;
    case 4:
      if (root == NULL)
      {
        printf("Expression tree not built yet.\n");
      }
      else
      {
        printf("Postorder traversal: ");
        postorderTraversal(root);
        printf("\n");
      }
      break;
    case 5:
      freeExpressionTree(root);
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}

