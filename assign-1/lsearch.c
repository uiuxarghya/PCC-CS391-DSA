#include <stdio.h>

void main()
{

	int n, i, num, flag = 0, pos = 0;

	printf("Enter number of elements : ");
	scanf("%d", &n);

	printf("\n");

	int arr[n];

	for (i = 0; i < n; i++)
	{
		printf("Enter arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}

	printf("\nEnter a number to search : ");
	scanf("%d", &num);

	for (i = 0; i < n; i++)
	{
		if (num == arr[i])
		{
			flag = 1;
			pos = i + 1;
			break;
		}
	}

	if (flag == 1)
		printf("Number found at position %d.\n", pos);
	else
		printf("Number not found!\n");
}
