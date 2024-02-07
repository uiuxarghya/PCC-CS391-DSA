#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;

	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			c[k] = a[i];
			k++;
			i++;
		} else {
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <= high) {
		c[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++) {
		a[i] = c[i];
	}
}

void mergeSort(int a[], int low, int high) {
	int mid;
	if (low < high) {
		mid = low + (high - low) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
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
	mergeSort(arr, 0, n - 1);
	printf("\nSorted array: ");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
