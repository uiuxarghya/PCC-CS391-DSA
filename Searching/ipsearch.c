#include <stdio.h>

int interpolationSearch(int arr[], int n, int key)
{
  int low = 0;      // Starting index
  int high = n - 1; // Ending index

  while (low <= high && key >= arr[low] && key <= arr[high])
  {
    if (low == high)
    {
      if (arr[low] == key)
        return low;
      return -1;
    }

    // Probing the position with keeping uniform distribution in mind.
    int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    if (arr[pos] == key)
      return pos;

    if (arr[pos] < key)
      low = pos + 1;
    else
      high = pos - 1;
  }
  return -1; // Element not found
}

int main()
{
  int n, key;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];

  printf("\nEnter the sorted array elements:\n");
  for (int i = 0; i < n; i++)
  {
    printf("Enter value for arr[%d]: ", i);
    scanf("%d", &arr[i]);
  }

  printf("\nArray elements are: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\nEnter the element you want to search for: ");
  scanf("%d", &key);

  int index = interpolationSearch(arr, n, key);
  if (index != -1)
    printf("Element %d found at index %d.\n", key, index);
  else
    printf("Element %d not found in the array.\n", key);

  return 0;
}
