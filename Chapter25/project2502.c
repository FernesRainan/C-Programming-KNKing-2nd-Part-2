// Write a program that obtains the name of a locale from the command line and then displays
// the values stored in the corresponding lconv structure. For example, if the locale is 
// "fi_FI" (Finland), the output of the program might look like this:
// For readability, the characters in 'grouping' and 'mon_grouping' should be displayed as
// decimal numbers. 

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 30

int main ()
{
	struct lconv * lc;
	
	char input[STR_MAX], ch, *current_locale;
	int i; 
	
	do {
		printf("Please enter locale: ");
		
		for (i = 0; (ch = getchar()) != '\n'; i++)
			input[i] = ch;
		input[i] = '\0';
			
		current_locale = setlocale(LC_ALL, input);
		if (current_locale == NULL) {
			printf("Locale information not available\nTry again.\n");
			continue;
		}
					
		lc = localeconv();
		
		printf("decimal_point = \"%s\"\n", lc->decimal_point);
		printf("thousands_sep = \"%s\"\n", lc->thousands_sep);
		printf("grouping = \"%s\"\n", lc->grouping);
		printf("mon_decimal_point = \"%s\"\n", lc->mon_decimal_point);
		printf("mon_thousands_sep = \"%s\"\n", lc->mon_thousands_sep);
		printf("mon_grouping = \"%s\"\n", lc->mon_grouping);
		printf("positive_sign = \"%s\"\n", lc->positive_sign);
		printf("negative_sign = \"%s\"\n", lc->negative_sign);
		printf("currency_symbol = \"%s\"\n", lc->currency_symbol);
		printf("frac_digits = %d\n", lc->frac_digits);
		printf("p_cs_precedes = %d\n", lc->p_cs_precedes);
		printf("n_cs_precedes = %d\n", lc->n_cs_precedes);
		printf("p_sep_by_space = %d\n", lc->p_sep_by_space);
		printf("n_sep_by_space = %d\n", lc->n_sep_by_space);
		printf("p_sign_posn = %d\n", lc->p_sign_posn);
		printf("n_sign_posn = %d\n", lc->n_sign_posn);
		printf("int_curr_symbol = \"%s\"\n", lc->int_curr_symbol);
		printf("int_frac_digits = %d\n", lc->int_frac_digits);
		printf("int_p_cs_precedes = %d\n", lc->int_p_cs_precedes);
		printf("int_n_cs_precedes = %d\n", lc->int_n_cs_precedes);
		printf("int_p_sep_by_space = %d\n", lc->int_p_sep_by_space);
		printf("int_n_sep_by_space = %d\n", lc->int_n_sep_by_space);
		printf("int_p_sign_posn = %d\n", lc->int_p_sign_posn);
		printf("int_n_sign_posn = %d\n", lc->int_n_sign_posn);
		
		printf("\nPress \'q\' to quit. Or continue: ");
	} while ((ch = getchar()) != 'q');
	
				
	return 0;
}	
