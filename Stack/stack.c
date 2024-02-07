#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int value)
{
    stack[++(*top)] = value;
}

int pop(int *stack, int *top)
{
    return stack[(*top)--];
}

void display(int *stack, int top)
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int *stack = (int *)malloc(100 * sizeof(int));
    int top = -1;

    int choice = 0;
    int value = 0;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            push(stack, &top, value);
            break;

        case 2:
            if (top == -1)
            {
                printf("\nStack is empty\n");
            }
            else
            {
                printf("\nPopped value: %d\n", pop(stack, &top));
            }
            break;

        case 3:
            if (top == -1)
            {
                printf("\nStack is empty.\n");
            }
            else
            {
                printf("\n");
                display(stack, top);
            }
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }

    return 0;
}
