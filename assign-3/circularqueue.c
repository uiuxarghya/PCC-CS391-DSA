#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
	int item = 0;
	if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
		printf("QUEUE OVERFLOW!\n");
		return;
	}
	printf("Enter the element to be inserted: ");
	scanf("%d", &item);
	if (front == -1) {
		front = 0;
		rear = 0;
	} else {
		if (rear == MAX - 1)
			rear = 0;
		else
			rear = rear + 1;
	}
	queue[rear] = item;
}

int Delete() {
	int item = 0;
	if (front == -1) {
		printf("QUEUE UNDERFLOW!\n");
		exit(1);
	}
	item = queue[front];
	if (front == rear) {
		front = -1;
		rear = -1;
	} else {
		if (front == MAX - 1)
			front = 0;
		else
			front = front + 1;
	}
	return item;
}

void display() {
	int i = 0;
	if (front == -1) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements are:\n");
	if (front <= rear) {
		for (i = front; i <= rear; i++)
			printf("%d ", queue[i]);
	} else {
		for (i = front; i <= MAX - 1; i++)
			printf("%d ", queue[i]);
		for (i = 0; i <= rear; i++)
			printf("%d ", queue[i]);
	}
	printf("\n");
}

int main() {
	int choice = 0;
	while (1) {
		printf("\n1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				insert();
				break;
			case 2:
				printf("Deleted element is: %d\n", Delete());
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice!\n");
		}
	}
	return 0;
}