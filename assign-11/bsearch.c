#include <stdio.h> 

int binarySearch(int arr[], int first, int last, int search) {
	int middle;

	if (first > last) {
		return -1;
	}

	middle = (first + last) / 2;

	if (arr[middle] == search) {
		return middle;
	} else if (arr[middle] < search) {
		return binarySearch(arr, middle + 1, last, search);
	} else {
		return binarySearch(arr, first, middle - 1, search);
	}
}

int main() {
	int n, i, search, first, last, position;

	printf("Enter number of elements in array : ");
	scanf("%d", &n);

	int arr[n];

	printf("Enter %d integers in ascending order. \n", n);

	for (i = 0; i < n; i++) {
		printf("Enter arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}

	printf("\nEnter value to find: ");
	scanf("%d", &search);

	first = 0;
	last = n - 1;
	position = binarySearch(arr, first, last, search);

	if (position == -1) {
		printf("%d is not present in the array. \n", search);
	} else {
		printf("%d is present at position %d. \n", search, position + 1);
	}

	return 0;
}

