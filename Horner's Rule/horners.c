#include <stdio.h>

double recurrHorner(double *coeff, int n, double x) {
  if (n == 0)  // base case
  {
    return coeff[0];  // return the first element of the array
  } else {
    return x * recurrHorner(coeff, n - 1, x) + coeff[n];  // recursive case
  }
}

int main() {
  int n, i;               // declare variables
  double x, value = 0.0;  // declare variables

  // ask the user for the number of elements
  printf("Enter the number of elements : ");
  scanf("%d", &n);

  printf("\n");

  double coeff[n];  // declare an array of size n

  // ask the user for the elements of the array
  for (i = 0; i < n; i++) {
    printf("Enter coeff[%d] : ", i);
    scanf("%lf", &coeff[i]);
  }

  // ask the user for the value of x
  printf("\nEnter the value of x : ");
  scanf("%lf", &x);

  // calculate the value of the polynomial using Horner's rule
  value = recurrHorner(coeff, n, x);

  printf("\nP(%0.2f) : %0.2f\n", x, value);

  return 0;
}