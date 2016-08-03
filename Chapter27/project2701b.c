// Make the following modifications to the quadratic.c program of Section 27.4;

// (b) Have the program test the discriminant before displaying the values of the roots. If the
// discriminant is negative, have the program display the roots in the same way as before. If it's
// nonnegative, have the program display the roots as real numbers (without an imaginary part).
// For example, if the quadratic equation is x^2 + x - 2 = 0, the output of the program would be
// root1 = 1
// root2 = -2

#include <complex.h>
#include <stdio.h>

int main (void)
{
	double a, b, c;
	double test;
	
	printf("This program finds the values of a quadric equation.\n");
	printf("Please enter three coefficients of the polynomial: ");
	scanf("%lf %lf %lf", &a, &b, &c); 
	
	test = b*b - 4*a*c;
	double complex discriminant_sqrt = csqrt(test);
	double complex root1 = (-b + discriminant_sqrt) / (2*a);
	double complex root2 = (-b - discriminant_sqrt) / (2*a);
	
	if (test >= 0) {
		printf("root1 = %g\n", creal(root1));
		printf("root2 = %g\n", creal(root2));
	}
	else {
		printf("root1 = %g + %gi\n", creal(root1), cimag(root1));
		printf("root2 = %g + %gi\n", creal(root2), cimag(root2));
	}
	
	return 0;
}
