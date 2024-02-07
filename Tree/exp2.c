#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Define a structure for the expression tree node
struct TreeNode 
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(char data) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build an expression tree from a postfix expression
struct TreeNode* buildExpressionTree(char postfix[]) 
{
    struct TreeNode* stack[100]; // Assuming the expression is not too large
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) 
    {
        struct TreeNode* newNode = createNode(postfix[i]);
        if (!isOperator(postfix[i])) 
        {
            stack[++top] = newNode;
        } 
        else 
        {
            // Pop two operands from the stack
            struct TreeNode* operand1 = stack[top--];
            struct TreeNode* operand2 = stack[top--];
            // Make the operator as the root of the subtree
            newNode->left = operand2;
            newNode->right = operand1;
            // Push the subtree back onto the stack
            stack[++top] = newNode;
        }
    }

    // Return root
    return stack[0];
}

// Function to print the expression tree in infix notation
void infixTraversal(struct TreeNode* root) 
{
    if (root != NULL) 
    {
        if (isOperator(root->data))
            printf("(");
        infixTraversal(root->left);
        printf("%c", root->data);
        infixTraversal(root->right);
        if (isOperator(root->data))
            printf(")");
    }
}

int main() 
{
    char postfix[MAX];
    printf("Enter the expression: ");
    scanf("%[^\n]%*c",postfix);
    struct TreeNode* root = buildExpressionTree(postfix);
    printf("Infix expression: ");
    infixTraversal(root);
    printf("\n");
    return 0;
}
