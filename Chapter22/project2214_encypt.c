// Modify Programming Project 15 from Chapter 8 so that the program prompts the user to
// enter the name of a file containing the message to be encrypted:
// Enter name of file to be encrypted: message.txt
// Enter shift amount (1-25): 3
// The program then writes the encrypted message to a file with the same name but an added
// extension of .enc. In this example, the original file name is message.txt, so the
// encrypted message will be stored in a file named message.txt.enc. There's no limits on
// the size of the file to be encrypted or on the length of each line in the file. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define INPUT_FILENAME_SIZE FILENAME_MAX - 4
#define OUTPUT_FILENAME_SIZE FILENAME_MAX

int main(void)
{
  char input[INPUT_FILENAME_SIZE + 1];
  char output[OUTPUT_FILENAME_SIZE + 1];
  int ch, i, shift_amount;
  int rc = 0;

  printf("Enter name of file to be encrypted: ");

  for (i = 0; i < INPUT_FILENAME_SIZE && (ch = getchar()) != '\n'; i++) {
    input[i] = output[i] = ch;
  }
  input[i] = output[i] =  '\0';
  strcat(output, ".enc");

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift_amount);

  FILE *istream, *ostream;
  if ((istream = fopen(input, "r")) == NULL) {
    perror(input);
    exit(EXIT_FAILURE);
  }

  if ((ostream = fopen(output, "w")) == NULL) {
    perror(output);
    if (fclose(istream) == EOF)
      perror(input);
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(istream)) != EOF) {
    if (islower(ch))
      ch = (( ch - 'a') + shift_amount) % 26 + 'a';
    if (isupper(ch))
      ch = (( ch - 'A') + shift_amount) % 26 + 'A';
    if (fputc(ch, ostream) == EOF) {
      perror(output);
      rc = -1;
      break;
    }
  }
  if (ferror(istream)) {
    perror(input);
    rc = -2;
  }

  if (fclose(istream) == EOF) {
    perror(input);
    rc = -3;
  }

  if (fclose(ostream) == EOF) {
    perror(output);
    rc = -4;
  }

  return rc;
}
