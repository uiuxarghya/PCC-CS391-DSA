#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insertFront() {
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
		if (front == 0)
			front = MAX - 1;
		else
			front = front - 1;
	}
	queue[front] = item;
}

void insertRear() {
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

int deleteFront() {
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

int deleteRear() {
	int item = 0;
	if (front == -1) {
		printf("QUEUE UNDERFLOW!\n");
		exit(1);
	}
	item = queue[rear];
	if (front == rear) {
		front = -1;
		rear = -1;
	} else {
		if (rear == 0)
			rear = MAX - 1;
		else
			rear = rear - 1;
	}
	return item;
}

void display() {
	int i = 0;
	if (front == -1) {
		printf("QUEUE IS EMPTY!\n");
		return;
	}
	printf("QUEUE ELEMENTS:\n");
	if (front <= rear) {
		for (i = front; i <= rear; i++)
			printf("%d\t", queue[i]);
	} else {
		for (i = front; i < MAX; i++)
			printf("%d\t", queue[i]);
		for (i = 0; i <= rear; i++)
			printf("%d\t", queue[i]);
	}
	printf("\n");
}

int main() {
	int choice = 0, item = 0;
	while (1) {
		printf("1. Insert at front\n");
		printf("2. Insert at rear\n");
		printf("3. Delete from front\n");
		printf("4. Delete from rear\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				insertFront();
				break;
			case 2:
				insertRear();
				break;
			case 3:
				item = deleteFront();
				printf("Deleted item: %d\n", item);
				break;
			case 4:
				item = deleteRear();
				printf("Deleted item: %d\n", item);
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
			default:
				printf("INVALID CHOICE!\n");
		}
	}
	return 0;
}