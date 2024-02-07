#include <stdio.h>

void insertionSort(int a[], int n) {
	int i, j, temp;
	if (n <= 1) {
		return;
	}
	insertionSort(a, n - 1);
	temp = a[n - 1];
	j = n - 2;
	while (j >= 0 && a[j] > temp) {
		a[j + 1] = a[j];
		j--;
	}
	a[j + 1] = temp;
}

int main() {
	int n, i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements: \n");
	for (i = 0; i < n; i++) {
		printf("Enter arr[%d] : ",i);
		scanf("%d", &arr[i]);
	}
	insertionSort(arr, n);
	printf("\nThe sorted array is: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
