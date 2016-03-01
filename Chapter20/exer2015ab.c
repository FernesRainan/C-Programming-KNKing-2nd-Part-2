#include <stdio.h>

// (a) Assume that the variable s has been declared as follows:
	struct {
//	int flag: 1;
		unsigned int flag: 1;
	} s;
// With some compilers, executing the following statements causes 1 to be displayed, but with
// other compilers, the output is -1. Explain the reason for this behavior.

int main(void)
{
	s.flag = 1;
	printf("s.flag = %d and s = %d\n", s.flag, s);
	
	return 0;
}

// (b) How can this problem be avoided?
