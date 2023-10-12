#include <stdio.h>
#include <stdlib.h>

// Define the structure for AVL tree node
typedef struct AVLNode
{
  int data;
  struct AVLNode *left;
  struct AVLNode *right;
  int height;
} AVLNode;

// Function to calculate the height of a node
int height(AVLNode *node)
{
  if (node == NULL)
    return 0;
  return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b)
{
  return (a > b) ? a : b;
}

// Function to create a new AVL node
AVLNode *newNode(int data)
{
  AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 1; // New node is initially added at the leaf level
  return node;
}

// Function to perform a right rotation
AVLNode *rightRotate(AVLNode *y)
{
  AVLNode *x = y->left;
  AVLNode *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  // Return new root
  return x;
}

// Function to perform a left rotation
AVLNode *leftRotate(AVLNode *x)
{
  AVLNode *y = x->right;
  AVLNode *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  // Return new root
  return y;
}

// Get the balance factor of a node
int getBalance(AVLNode *node)
{
  if (node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
AVLNode *insert(AVLNode *root, int data)
{
  // Perform the standard BST insert
  if (root == NULL)
    return newNode(data);

  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);
  else // Duplicate keys are not allowed
    return root;

  // Update the height of the current node
  root->height = 1 + max(height(root->left), height(root->right));

  // Get the balance factor of this node to check if it became unbalanced
  int balance = getBalance(root);

  // Left Heavy (LL or LR)
  if (balance > 1 && data < root->left->data)
    return rightRotate(root);

  // Right Heavy (RR or RL)
  if (balance < -1 && data > root->right->data)
    return leftRotate(root);

  // Left Right Heavy (LR)
  if (balance > 1 && data > root->left->data)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Left Heavy (RL)
  if (balance < -1 && data < root->right->data)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Function to find the minimum value node in a given AVL tree
AVLNode *minValueNode(AVLNode *node)
{
  AVLNode *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Function to delete a node from the AVL tree
AVLNode *deleteNode(AVLNode *root, int data)
{
  if (root == NULL)
    return root;

  if (data < root->data)
    root->left = deleteNode(root->left, data);
  else if (data > root->data)
    root->right = deleteNode(root->right, data);
  else
  {
    if ((root->left == NULL) || (root->right == NULL))
    {
      AVLNode *temp = root->left ? root->left : root->right;

      // No child case
      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else             // One child case
        *root = *temp; // Copy the contents of the non-empty child

      free(temp);
    }
    else
    {
      AVLNode *temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);

  // Left Heavy (LL or LR)
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  // Right Heavy (RR or RL)
  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  // Left Right Heavy (LR)
  if (balance > 1 && getBalance(root->left) < 0)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Left Heavy (RL)
  if (balance < -1 && getBalance(root->right) > 0)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Function to search for a key in the AVL tree
AVLNode *search(AVLNode *root, int data)
{
  if (root == NULL || data == root->data)
    return root;

  if (data < root->data)
    return search(root->left, data);

  return search(root->right, data);
}

// Function to print an integer with a space
void printInt(int data)
{
  printf("%d ", data);
}

// Function to print the AVL tree in in-order traversal
void inorderTraversal(AVLNode *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printInt(root->data);
    inorderTraversal(root->right);
  }
}

// Function to print the AVL tree in pre-order traversal
void preorderTraversal(AVLNode *root)
{
  if (root != NULL)
  {
    printInt(root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

// Function to print the AVL tree in post-order traversal
void postorderTraversal(AVLNode *root)
{
  if (root != NULL)
  {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printInt(root->data);
  }
}

// Function to insert an integer (user input)
int insertInteger(AVLNode **root)
{
  int value;
  printf("Enter an integer to insert: ");
  scanf("%d", &value);
  *root = insert(*root, value);
  return value;
}

// Function to delete an integer (user input)
int deleteInteger(AVLNode **root)
{
  int value;
  printf("Enter an integer to delete: ");
  scanf("%d", &value);
  *root = deleteNode(*root, value);
  return value;
}

// Function to search for an integer (user input)
void searchInteger(AVLNode *root)
{
  int value;
  printf("Enter an integer to search: ");
  scanf("%d", &value);
  AVLNode *result = search(root, value);
  if (result != NULL)
    printf("Key %d found in the AVL tree.\n", value);
  else
    printf("Key %d not found in the AVL tree.\n", value);
}

// main method
int main()
{
  AVLNode *root = NULL;
  int choice;

  while (1)
  {
    printf("\n1. Insert\n2. Delete\n3. Search\n4. Print Pre-order\n5. Print In-order\n6. Print Post-order\n7. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      insertInteger(&root);
      break;
    case 2:
      deleteInteger(&root);
      break;
    case 3:
      searchInteger(root);
      break;
    case 4:
      printf("Pre-order traversal of AVL tree: ");
      preorderTraversal(root);
      printf("\n");
      break;
    case 5:
      printf("In-order traversal of AVL tree: ");
      inorderTraversal(root);
      printf("\n");
      break;
    case 6:
      printf("Post-order traversal of AVL tree: ");
      postorderTraversal(root);
      printf("\n");
      break;
    case 7:
      exit(0);
    default:
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}

