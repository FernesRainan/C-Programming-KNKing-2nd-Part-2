// Write the following function:
// double evaluate_polynomial(double a[], int n, double x);
// The function should return the value of the polynomial .. , where the
// a(i)'s are stored in corresponding elements of the array a, which has length n + 1. 
// Have the function use Horner's Rule to compute the value of the polynomial:
// ((...((a(n)x+a(n-1))x + a(n-2))x +...)x + a(1))x + a(0)
// Use the fma function to perform the multiplication and additions.

#include <stdio.h>
#include <math.h>
#define VALUE 2

double evaluate_polynomial (double a[], int n, double x)
{ 
	int i;
	long double result = 0.0;
		
	for (i = n ; i > 0 ; i-- )
		result = fma(result, x, a[n - i]);
			
	return result;
}

int main (void)
{
	double coeffs[] = { 2,0,3,1};
	
	printf("%5.1f\n", evaluate_polynomial(coeffs, sizeof(coeffs)/sizeof(double), VALUE));
	
	return 0;
}


	