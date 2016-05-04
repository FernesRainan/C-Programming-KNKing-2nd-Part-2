// Write a program that converts a Windows text file to a UNIX text file. (See Section 22.1
// for a discussion of the differences between Windows and UNIX text files)

// Write a program that converts a UNIX text file to a Windows text file. 

// In each case, have the program obtain the names of both files from the command line. 
// Hint: Open the input file in "rb" mode and the output file in "wb" mode. 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define BUFFER_MAX 1024
#define UNIX2DOS 
//#define DOS2UNIX

int convert_line_endings(int argc, char *argv[], 
	int (*detect_newline)(FILE *, bool*), int (*write_newline)(FILE *))
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s [input file] [output file]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *input  = argv[1];
  char *ouput =  argv[2];;
  FILE *in_fp, *out_fp;
  unsigned char buffer[BUFFER_MAX];
  int ch, rc = 0;
  size_t i = 0;
  bool newline = false;

  if ((in_fp = fopen(input, "rb")) == NULL) {
    perror(input);
    exit(EXIT_FAILURE);
  }

  if ((out_fp = fopen(ouput, "wb")) == NULL) {
    perror(ouput);
    if (fclose(in_fp) == EOF)
      perror(input);
    exit(EXIT_FAILURE);
  }

  do {
    ch = detect_newline(in_fp, &newline);
    if (!newline && ch != EOF)
      buffer[i++] = (unsigned char)ch;

    if (i == BUFFER_MAX || newline || (ch == EOF && i > 0)) {
      if (fwrite(buffer, sizeof(buffer[0]), i, out_fp) < i) {
        perror(ouput);
        errno = 0;
        rc = EXIT_FAILURE;
        break;
      }
      i = 0;
    }

    if (newline) {
      if (write_newline(out_fp) == EOF) {
        perror(ouput);
        errno = 0;
        rc = EXIT_FAILURE;
        break;
      }
      newline = false;
    }
  } while (ch != EOF);

  if (ferror(in_fp)) {
    perror(input);
    rc = EXIT_FAILURE;
  }

  if (fclose(in_fp) == EOF) {
    perror(input);
    rc = EXIT_FAILURE;
  }

  if (fclose(out_fp) == EOF) {
    perror(ouput);
    rc = EXIT_FAILURE;
  }

  return rc;
}

#if defined(DOS2UNIX)
static int detect_dos_newline(FILE *fp, bool *is_newline)
{
  int ch = fgetc(fp);
  if (ch == 0x0D) {
    if ((ch = fgetc(fp)) == 0x0A)
      *is_newline = true;
  }
  return ch;
}

static int write_unix_newline(FILE *fp)
{
  return fputc(0x0A, fp);
}
int main(int argc, char *argv[])
{
  return convert_line_endings(argc, argv, detect_dos_newline, write_unix_newline);
}
#elif defined(UNIX2DOS)
static int detect_unix_newline(FILE *fp, bool *is_newline)
{
  int ch;
  if ((ch = fgetc(fp)) == 0x0A)
    *is_newline = true;

  return ch;
}

static int write_dos_newline(FILE *fp)
{
  static char newline[] = {0x0D, 0x0A};
  return fputs(newline, fp);
}

int main(int argc, char *argv[])
{
  return convert_line_endings(argc, argv, detect_unix_newline, write_dos_newline);
}
#endif
