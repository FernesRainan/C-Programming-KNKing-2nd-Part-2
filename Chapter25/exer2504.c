// Give a C string literal that represents each of the following phrases.
// The character are reporesented by single-byte Latin-1 characters. 

#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "en_IE.iso88591");
	
	char *a = "C\xf4te d'Azur";
	//char *b = "cr\xe8me br\xfbl\xe9e";
	//char *c = "cr\xe8me fra\xeeche";
	char *d = "Fahrvergn\xfcgen";
	char *e = "t\xeate-\xe0-t\xeate";
	
	//printf("%s\n%s\n%s\n%s\n%s\n", a, b, c, d, e);
	printf("%s\n%s\n%s\n", a, d, e);
	return 0;
}
