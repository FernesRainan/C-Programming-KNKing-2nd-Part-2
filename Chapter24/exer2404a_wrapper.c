// (a) Write a "wrapper" function named try_math_fcn that calls a math function 
// (assumed to have a double argument and return a double value) and then checks 
// whether the call succeeded. Here's how we might use try_math_fcn:
// y = try_math_fcn(sqrt, x, "Error in call of sqrt");
// if the call sqrt(x) is successful, try_math_fcn returns the value computed by sqrt. 
// If the call fails, try_math_fcn calls perror to print the message Error in call of
// sqrt, then calls exit to terminate the program. 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

double try_math_fcn(double (*f)(double), double x, const char *msg)
{
	double result;
	
	errno = 0;
	result = (*f)(x);
	if (errno != 0) {
		perror(msg);
		exit(EXIT_FAILURE);
	}
	
	return result;
}

		
