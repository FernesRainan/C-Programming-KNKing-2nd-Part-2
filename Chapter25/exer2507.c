// Modify the program fragment in Exercise 6 by replacing as many tokens as possible
// by digraphs and macros defined in <iso646.h>

// while ((orig_char = getchar()) != EOF) {
// 	new_char = orig_char ^ KEY;
// 	if (isprint(orig_char) && isprint(new_char))
// 		putchar(new_char);
// 	else
// 		putchar(orig_char);
// }

 while ((orig_char = getchar()) not_eq EOF) <%
 	new_char = orig_char xor KEY;
 	if (isprint(orig_char) and isprint(new_char))
 		putchar(new_char);
 	else
 		putchar(orig_char);
 %>
	
