#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left, *right;
} TreeNode;

// Function to create a new node
TreeNode *createNode(int value) {
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->data = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Function to insert a new node
TreeNode *insertNode(TreeNode *root, int value) {
  if (root == NULL) {
    return createNode(value);
  }

  if (value <= root->data) {
    root->left = insertNode(root->left, value);
  } else if (value > root->data) {
    root->right = insertNode(root->right, value);
  }

  return root;
}

// Function to traverse the tree in pre-order recursively
void preOrder(TreeNode *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

// Function to traverse the tree in in-order recursively
void inOrder(TreeNode *root) {
  if (root != NULL) {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
  }
}

// Function to traverse the tree in post-order recursively
void postOrder(TreeNode *root) {
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
  }
}

// Function to search for a node with a given value
TreeNode *searchNode(TreeNode *root, int target) {
  if (root == NULL || root->data == target) {
    return root;
  }

  if (target < root->data) {
    return searchNode(root->left, target);
  } else if (target > root->data) {
    return searchNode(root->right, target);
  }

  return NULL;
}

// Function to find the minimum value in the tree
TreeNode *findMin(TreeNode *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->left != NULL) {
    return findMin(root->left);
  }
  return root;
}

// Function to find the maximum value in the tree
TreeNode *findMax(TreeNode *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->right != NULL) {
    return findMax(root->right);
  }
  return root;
}

// Function to find the height of the tree
int findHeight(TreeNode *root) {
  if (root == NULL) {
    return -1;
  }
  int leftHeight = findHeight(root->left);
  int rightHeight = findHeight(root->right);
  return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int main() {
  TreeNode *root = NULL; // Pointer to the root node
  int choice, value; // Variables to store user choice and value

  while (1) {
    printf("1. Insert\n");
    printf("2. Pre-order Traversal\n");
    printf("3. In-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Search\n");
    printf("6. Find Min\n");
    printf("7. Find Max\n");
    printf("8. Find Height\n");
    printf("9. Exit\n");
    printf("Enter your choice: "); // ask the user for their choice
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to insert: "); // ask the user for the value to insert
        scanf("%d", &value);
        root = insertNode(root, value); // Insert value into the tree
        break;
      case 2:
        printf("Pre-order Traversal: ");
        preOrder(root); // Traverse the tree in pre-order
        printf("\n");
        break;
      case 3:
        printf("In-order Traversal: ");
        inOrder(root); // Traverse the tree in in-order
        printf("\n");
        break;
      case 4:
        printf("Post-order Traversal: ");
        postOrder(root); // Traverse the tree in post-order
        printf("\n");
        break;
      case 5:
        printf("Enter the value to search: "); // ask the user for the value to search
        scanf("%d", &value);
        TreeNode *searchResult = searchNode(root, value); // Search for the value

        if (searchResult != NULL) {
          printf("Value found.\n");
        } else {
          printf("Value not found.\n");
        }
        break;
      case 6:
        printf("Minimum value: %d\n", findMin(root)->data); // Find the minimum value
        break;
      case 7:
        printf("Maximum value: %d\n", findMax(root)->data); // Find the maximum value
        break;
      case 8:
        printf("Height of the tree: %d\n", findHeight(root)); // Find the height of the tree
        break;
      case 9:
        exit(0); // Exit the program
      default:
        printf("Invalid choice.\n");
    }
  }
}