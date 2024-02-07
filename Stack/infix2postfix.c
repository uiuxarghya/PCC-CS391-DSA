#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *stack, int *top, char value)
{
    stack[++(*top)] = value;
}

char pop(char *stack, int *top)
{
    return stack[(*top)--];
}

void convertToPostfix(char *expression)
{
    char *stack = (char *)malloc(100 * sizeof(char));
    int top = -1;
    int length = strlen(expression);

    printf("Postfix Expression: ");

    for (int i = 0; i < length; i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            printf("%c", expression[i]);
        }
        else
        {
            if (expression[i] == '(')
            {
                push(stack, &top, expression[i]);
            }
            else if (expression[i] == ')')
            {
                while (stack[top] != '(')
                {
                    printf("%c", pop(stack, &top));
                }
                pop(stack, &top);
            }
            else
            {
                while (top != -1 && stack[top] != '(' && expression[i] <= stack[top])
                {
                    printf("%c", pop(stack, &top));
                }
                push(stack, &top, expression[i]);
            }
        }
    }

    while (top != -1)
    {
        printf("%c", pop(stack, &top));
    }
    printf("\n");

    free(stack);
}

int main()
{
    char *expression = (char *)malloc(100 * sizeof(char));
    printf("Enter the infix expression: ");
    scanf("%s", expression);

    convertToPostfix(expression);

    free(expression);

    return 0;
}
