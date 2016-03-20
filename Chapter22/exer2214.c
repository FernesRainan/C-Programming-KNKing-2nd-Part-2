// Write your own version of the fgets function. Make it behave as much like the real
// fgets function as possible; in particular, make sure that it has the proper return value. To
// avoid conflicts with the standard library, don't name your function fgets. 

char *fget_string(char *s, int n, FILE *stream)
{
	int ch, len = 0;
	
	while (len < n - 1) {
		if ((ch = getc(stream)) == EOF) {
			if (len == 0 || ferror(stream))
				return NULL;
			break;
		}
		s[len++] = ch;
		if (ch == '\n')
			break;
	}
	
	s[len] = '\0';
	
	return s;
}

// Write your own version of fputs, following the same rules as in part (a)

int fput_string(const char *s, FILE *stream)
{
	while (*s != '\0') {
		if(putc(*s, stream) == EOF)
			return EOF;
		s++;
	}
	
	return 0;
}
