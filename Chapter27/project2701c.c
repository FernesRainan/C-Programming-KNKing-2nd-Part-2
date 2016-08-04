// Make the following modifications to the quadratic.c program of Section 27.4;

// (c) Modify the program so that it displays a complex number with a negative imaginary
// part as a - bi insteadof a + -bi. For example, the output of the program with the original
// coefficients would be
// root1 = -0.2 + 0.4i
// root2 = -0.2 - 0.4i

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
		printf("root2 = %g - %gi\n", creal(root2), cabs(cimag(root2)));
	}
	
	return 0;
}
