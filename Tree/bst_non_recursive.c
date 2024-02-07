#include <stdio.h>
#include <stdlib.h>

// Define the binary search tree node structure using typedef
typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

// Structure for a stack to be used in traversals
typedef struct Stack
{
  TreeNode **data;
  int size;
  int capacity;
} Stack;

// Function to create a new stack
Stack *createStack(int capacity)
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->data = (TreeNode **)malloc(sizeof(TreeNode *) * capacity);
  stack->size = 0;
  stack->capacity = capacity;
  return stack;
}

// Function to push a node onto the stack
void push(Stack *stack, TreeNode *node)
{
  if (stack->size >= stack->capacity)
  {
    // Stack is full, need to resize
    stack->capacity *= 2;
    stack->data = (TreeNode **)realloc(stack->data, sizeof(TreeNode *) * stack->capacity);
  }
  stack->data[stack->size++] = node;
}

// Function to pop a node from the stack
TreeNode *pop(Stack *stack)
{
  if (stack->size <= 0)
    return NULL;
  return stack->data[--stack->size];
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
  return stack->size == 0;
}

// Function to create a new BST node
TreeNode *createNode(int data)
{
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Function to insert a node into the BST

TreeNode *insert(TreeNode *root, int data)
{
  if (root == NULL)
  {
    return createNode(data);
  }
  if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
  }
  return root;
}

// Non-Recursive Preorder Traversal
void preorderNonRecursive(TreeNode *root)
{
  if (root == NULL)
    return;

  Stack *stack = createStack(100); // Create a stack for traversing nodes
  TreeNode *current = root;

  while (current != NULL || !isEmpty(stack))
  {
    while (current != NULL)
    {
      printf("%d ", current->data);
      push(stack, current);
      current = current->left;
    }

    current = pop(stack);
    current = current->right;
  }

  free(stack->data);
  free(stack);
}

// Non-Recursive Inorder Traversal
void inorderNonRecursive(TreeNode *root)
{
  if (root == NULL)
    return;

  Stack *stack = createStack(100); // Create a stack for traversing nodes
  TreeNode *current = root;

  while (current != NULL || !isEmpty(stack))
  {
    while (current != NULL)
    {
      push(stack, current);
      current = current->left;
    }

    current = pop(stack);
    printf("%d ", current->data);
    current = current->right;
  }

  free(stack->data);
  free(stack);
}

// Non-Recursive Postorder Traversal
void postorderNonRecursive(TreeNode *root)
{
  if (root == NULL)
    return;

  Stack *stack1 = createStack(100); // First stack for traversal
  Stack *stack2 = createStack(100); // Second stack for storing postorder nodes
  TreeNode *current = root;

  push(stack1, current);

  while (!isEmpty(stack1))
  {
    current = pop(stack1);
    push(stack2, current);

    if (current->left != NULL)
    {
      push(stack1, current->left);
    }

    if (current->right != NULL)
    {
      push(stack1, current->right);
    }
  }

  while (!isEmpty(stack2))
  {
    current = pop(stack2);
    printf("%d ", current->data);
  }

  free(stack1->data);
  free(stack1);
  free(stack2->data);
  free(stack2);
}

// Function to find the height of the BST using level-order traversal (without recursion)
int findHeight(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int height = -1;                 // Initialize height as -1
  Stack *stack = createStack(100); // Create a stack for traversing nodes
  TreeNode *current = root;

  while (current != NULL || !isEmpty(stack))
  {
    while (current != NULL)
    {
      push(stack, current);
      current = current->left;
    }

    current = pop(stack);

    // If the popped item has a right child, push it onto the stack
    if (current->right != NULL)
    {
      push(stack, current->right);
    }

    // Update the height
    height = (stack->size > height) ? stack->size : height;

    current = NULL;
  }

  free(stack->data);
  free(stack);

  return height;
}

int main()
{
  TreeNode *root = NULL;
  int n, data;
  int choice;

  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Non-Recursive Preorder Traversal\n");
    printf("3. Non-Recursive Inorder Traversal\n");
    printf("4. Non-Recursive Postorder Traversal\n");
    printf("5. Find Height of the Tree\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the data for the new node: ");
      scanf("%d", &data);
      root = insert(root, data);
      break;
    case 2:
      printf("Non-Recursive Preorder Traversal: ");
      preorderNonRecursive(root);
      printf("\n");
      break;
    case 3:
      printf("Non-Recursive Inorder Traversal: ");
      inorderNonRecursive(root);
      printf("\n");
      break;
    case 4:
      printf("Non-Recursive Postorder Traversal: ");
      postorderNonRecursive(root);
      printf("\n");
      break;
    case 5:
      printf("Height of the tree: %d\n", findHeight(root));
      break;
    case 6:
      // Exit the program
      exit(0);
    default:
      printf("Invalid choice! Please enter a valid option.\n");
    }
  }

  return 0;
}
