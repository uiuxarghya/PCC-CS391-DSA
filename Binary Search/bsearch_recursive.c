#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;  // calculate the middle index
    if (arr[mid] == target) {
      return mid;  // target found
    } else if (arr[mid] < target) {
      return binarySearch(arr, mid + 1, right, target);
    } else {
      return binarySearch(arr, left, mid - 1, target);
    }
  }
  return -1;  // target not found
}

int main() {
  int n, i, key, pos;  // declare variables

  // ask the user for the size of the array
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  printf("\n");

  int arr[n];  // declare an array of size n

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
  pos = binarySearch(arr, 0, n, key);

  if (pos == -1) {
    printf("\nNumber not found!");
  } else {
    printf("\nNumber found at index %d.", pos);
  }

  return 0;
}