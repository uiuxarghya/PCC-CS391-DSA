#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

void push(char *stack[], int *top, char *value) {
    stack[++(*top)] = value;
}

char* pop(char *stack[], int *top) {
    return stack[(*top)--];
}

char* preToPost(char *pre_exp) {
    char *stack[100];
    int top = -1;
    int length = strlen(pre_exp);

    for (int i = length - 1; i >= 0; i--) {
        char* temp = (char*)malloc(2 * sizeof(char));
        temp[0] = pre_exp[i];
        temp[1] = '\0';

        if (isOperator(pre_exp[i])) {
            char *op1 = pop(stack, &top);
            char *op2 = pop(stack, &top);

            char *temp_expr = (char*)malloc((strlen(op1) + strlen(op2) + 2) * sizeof(char));
            strcpy(temp_expr, op1);
            strcat(temp_expr, op2);
            strcat(temp_expr, temp);

            free(op1);
            free(op2);

            push(stack, &top, temp_expr);
        } else {
            push(stack, &top, temp);
        }
    }

    char *result = pop(stack, &top);

    // Allocate memory for the final result to be returned
    char *final_result = (char *)malloc((strlen(result) + 1) * sizeof(char));
    strcpy(final_result, result);

    // Free dynamically allocated memory for temporary expressions and result
    free(result);
    while (top != -1) {
        free(pop(stack, &top));
    }

    return final_result;
}

int main() {
    char pre_exp[100];
    printf("Enter the prefix expression: ");
    scanf("%s", pre_exp);

    char *post_exp = preToPost(pre_exp);
    printf("Postfix expression: %s\n", post_exp);

    // Free dynamically allocated memory for the postfix expression
    free(post_exp);

    return 0;
}

