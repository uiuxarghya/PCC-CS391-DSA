#include <stdio.h>

double recurrHorner(double coeff[], int n, double x)
{
	if (n == 0)
	{
		return coeff[0];
	}
	else
	{
		return coeff[n] + x * recurrHorner(coeff, n - 1, x);
	}
}

void main()
{

	int n, i;
	double x, value = 0.0;

	printf("Enter number of elements : ");
	scanf("%d", &n);

	printf("\n");

	double coeff[n];

	for (i = 0; i < n; i++)
	{
		printf("Enter coeff[%d] : ", i);
		scanf("%lf", &coeff[i]);
	}

	printf("\nEnter value of x : ");
	scanf("%lf", &x);

	value = recurrHorner(coeff, n, x);

	printf("P(%0.2f) : %0.2f\n", x, value);
}
