#include <stdio.h>

int lsearch(int arr[], int n, int key) {
  int i, pos = 0;  // declare variables
  for (i = 0; i < n; i++) {
    if (arr[i] == key) {
      pos = i;
      break;
    } else {
      pos = -1; // if the key is not found, return -1
    }
  }
  return pos;  // return the position of the key
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
  printf("\nThe array is: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  // ask the user for the element to search
  printf("\nEnter the element to search: ");
  scanf("%d", &key);

  // search for the key in the array using lsearch function
  pos = lsearch(arr, n, key);

  if (pos == -1) {
    printf("\nNumber not found!");
  } else {
    printf("\nNumber found at index %d.", pos);
  }

  return 0;
}