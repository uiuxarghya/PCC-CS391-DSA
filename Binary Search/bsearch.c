#include <stdio.h>

int bsearch(int arr[], int size, int target) {
  int left = 0;          // declare variables
  int right = size - 1;  // declare variables

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;  // target found
    } else if (arr[mid] < target) {
      left = mid + 1;  // search the right half
    } else {
      right = mid - 1;  // search the left half
    }
  }
  return -1;  // target not found
}

int main() {
  int n, i, key, pos;  // declare variables

  // ask the user for the size of the array
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];  // declare an array of size n

  printf("\nEnter the sorted array elements:\n");

  // ask the user for the elements of the array
  for (i = 0; i < n; i++) {
    printf("Enter arr[%d]: ", i);
    scanf("%d", &arr[i]);
  }

  // print the array
  printf("\nGiven Array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  // ask the user for the element to search
  printf("\nEnter the element to search: ");
  scanf("%d", &key);

  // search for the key in the array using bsearch function
  pos = bsearch(arr, n, key);

  if (pos == -1) {
    printf("\nNumber not found!");
  } else {
    printf("\nNumber found at index %d.", pos);
  }

  return 0;
}