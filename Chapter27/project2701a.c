// Make the following modifications to the quadratic.c program of Section 27.4;

// (a) Have the user enter the coefficients of the polynomial (the values of the variables a, 
// b, and c).

#include <complex.h>
#include <stdio.h>

int main (void)
{
	double a, b, c;
	printf("This program finds the values of a quadric equation.\n");
	printf("Please enter three coefficients of the polynomial: ");
	scanf("%lf %lf %lf", &a, &b, &c); 
	
	double complex discriminant_sqrt = csqrt(b*b - 4*a*c);
	double complex root1 = (-b + discriminant_sqrt) / (2*a);
	double complex root2 = (-b - discriminant_sqrt) / (2*a);
	
	printf("root1 = %g + %gi\n", creal(root1), cimag(root1));
	printf("root2 = %g + %gi\n", creal(root2), cimag(root2));
	
	return 0;
}
