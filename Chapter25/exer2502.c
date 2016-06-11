// The Shift-JIS encoding for kanji requires either one or two bytes per character. If the first
// byte of a character is between 0x81 and 0x9f or between 0xe0 and 0xef, a second byte
// is required. (Any other byte is treated as a whole character.) The second byte must be
// between 0x40 and 0x7e or between 0x80 and 0xfc. (All ranges are inclusive) For each
// of the following strings, give the value that the mbcheck function of Section 25.2 will
// return when passed that string as its argument, assuming that multibyte characters are
// encoded using Shift-JIS in the current locale. 

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int mbcheck(const char *s)
{ 
	int n;
	
	for (mblen(NULL, 0); ; s += n)
		if ((n = mblen(s, MB_CUR_MAX)) <= 0)
			return n;
}

int main (void)
{
	setlocale(LC_ALL, "ja_JP");
	
	char *s1 = "\x05\x87\x80\x36\xed\xaa";
	char *s2 = "\x20\xe4\x50\x88\x3f";
	char *s3 = "\xde\xad\xbe\xef";
	char *s4 = "\x8a\x60\x92\x74\x41";
		
	printf("s1 = %d\n", mbcheck(s1));
	printf("s2 = %d\n", mbcheck(s2));
	printf("s3 = %d\n", mbcheck(s3));
	printf("s4 = %d\n", mbcheck(s4));	
	
	return 0;
}
