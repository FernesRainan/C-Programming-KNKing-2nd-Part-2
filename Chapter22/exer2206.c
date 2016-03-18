// Write a call of printf that prints
// 1 widget
// if the widget variable (of type int) has the value 1, and
// n widgets
// otherwise, where n is the values of widget, You are not allowed to use the if statement or
// any other statement; the answer must be a single call of printf.

#include <stdio.h>

int main(void)
{
	int widget;
	
	for (widget = 1; widget < 5; widget++)
		printf(widget == 1 ? "%d widget\n" : "%d widgets\n", widget);
	
	return 0;
}

