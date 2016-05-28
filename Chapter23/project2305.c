// Suppose that money is deposited into a savings account and left for t years. Assume that the
// annual interest rate is r and that interest is compounded continuously. The formula A(t) = 
// Pe^rt can be used to calculate the final value of the account, where P is the original amount
// deposited. For example, $1000 left on deposit for 10 years at 6% interest would be worth
// $1000 * e^(0.06*10) = $1,822.12. Write a program that displays
// the result of this calculation after prompting the user to enter the original amount
// deposited, the interest rate, and the number of years. 

#include <stdio.h>
#include <math.h>

int main (void)
{
	float deposit, interest; 
	int year;
	
	printf("This program calculate the formula A(t) = Pe^rt for the final value of the account.\n");
	printf("Enter the original amount: ");
	scanf(" %f", &deposit);
	printf("Enter the interest rate: (0.xx) ");
	scanf(" %f", &interest);
	printf("Enter the years: ");
	scanf(" %d", &year);
	
	printf("The final value of the account is $%.2lf.\n", deposit * exp(interest * year));
	
	return 0;
}

	
	
