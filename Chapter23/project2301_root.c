// Write a program that finds the roots of the equation ax^2 + bx + c = 0 using the formula
// Have the program prompt for the values of a, b, and c, then print both values of x. (If b^2 - 4ac
// is negative, the program should instead print a message to the effect that the roots are complex.)

#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c, determinant, r1, r2, real, imag;
	printf(" Enter coefficients a, b and c:  ");
	scanf("%f%f%f", &a, &b, &c);
	determinant = b * b -4 * a * c;
	
	if (determinant > 0) {
		r1 = (-b + sqrt(determinant))/(2*a);
		r2 = (-b - sqrt(determinant))/(2*a);
		printf("Roots are: %.2f and %.2f\n", r1, r2);
	}
	
	else if (determinant == 0) {
		r1 = r2 = -b / (2 * a);
		printf("Roots are: %.2f\n", r1);
	}
	
	else {
		real = -b / (2 * a);
		imag = sqrt(-determinant) / (2 * a);
		printf("Roots are: %.2f + %.2fi and %.2f - %.2fi\n", real, imag, real, imag);
	}
	
	return 0;
}


		
