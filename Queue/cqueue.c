#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct cqueue
{
    int front;
    int rear;
    int queue[MAX];
} CQueue;

void insert(CQueue *cq)
{
    int item = 0;
    if ((cq->front == 0 && cq->rear == MAX - 1) || (cq->front == cq->rear + 1))
    {
        printf("QUEUE OVERFLOW!\n");
    }
    else
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &item);

        if (cq->front == -1)
        {
            cq->front = 0;
            cq->rear = 0;
        }
        else
        {
            if (cq->rear == MAX - 1)
                cq->rear = 0;
            else
                cq->rear++;
        }
        cq->queue[cq->rear] = item;
    }
}

int Delete(CQueue *cq)
{
    int item = 0;
    if ((cq->front == -1))
    {
        printf("QUEUE UNDERFLOW!\n");
        return 0xffff;
    }
    else
    {
        item = cq->queue[cq->front];

        if (cq->front == cq->rear)
        {
            cq->front = -1;
            cq->rear = -1;
        }
        else
        {
            if (cq->front == MAX - 1)
                cq->front = 0;
            else
                cq->front++;
        }
        return item;
    }
}

void display(CQueue *cq)
{
    int item = 0;
    if (cq->front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elemrnts are : ");
        if (cq->front <= cq->rear)
        {
            for (int i = cq->front; i <= cq->rear; i++)
            {
                printf("%d ", cq->queue[i]);
            }
        }
        else
        {
            for (int i = cq->front; i <= MAX - 1; i++)
                printf("%d ", cq->queue[i]);
            for (int i = 0; i <= cq->rear; i++)
                printf("%d ", cq->queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice = 0;
    CQueue cq;
    cq.front = -1;
    cq.rear = -1;
    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            insert(&cq);
            break;
        }
        case 2:
        {
            int elm = Delete(&cq);
            if (elm != 0xffff)
                printf("Element deleted is %d\n", elm);
            break;
        }
        case 3:
        {
            display(&cq);
            break;
        }
        case 4:
            exit(1);
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}
