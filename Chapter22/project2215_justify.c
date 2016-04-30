// Modify the justify program of Section 15.3 so that it reads from one text file and writes
// to another. Have the program obtain the names of both files from the command line. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_WORD_LEN 28
#define MAX_LINE_LEN 80

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

void invocation_error(char *program, char *usage);
void memory_error(char *file, unsigned int line, const char *func);
void print_error(char *, char *);
void exit_error(char *, char *);
int is_file_name_error(int);

/**********************************************************
 * clear_line: Clears the current line.                   *
 **********************************************************/
void clear_line(void);

/**********************************************************
 * add_word: Adds word to the end of the current line.    *
 *           If this is not the first word on the line,   *
 *           puts one space before word.                  *
 **********************************************************/
void add_word(const char *word);

/**********************************************************
 * space_remaining: Returns the number of characters left *
 *                  in the current line.                  *
 **********************************************************/
int space_remaining(void);

/**********************************************************
 * write_line: Writes the current line with               *
 *             justification.                             *
 **********************************************************/
void write_line(void);

/**********************************************************
 * flush_line: Writes the current line without            *
 *             justification. If the line is empty, does  *
 *             nothing.                                   *
 **********************************************************/
void flush_line(void);

/**********************************************************
 * read_word: Reads the next word from the input and      *
 *            stores it in word. Makes word empty if no   *
 *            word could be read because of end-of-file.  *
 *            Truncates the word if its length exceeds    *
 *            len.                                        *
 **********************************************************/
int read_word(char *word, int len);

int main(int argc, char *argv[])
{
  char word[MAX_WORD_LEN+2];
  int word_len;

  if (argc != 3)
    invocation_error(argv[0], "[input file] [output file]");

  if (!freopen(argv[1], "r", stdin))
    exit_error(argv[0], argv[1]);

  if (!freopen(argv[2], "w", stdout)) {
    if (fclose(stdin) == EOF)
      perror(argv[1]);
    exit_error(argv[0], argv[2]);
  }

  clear_line();
  for (;;) {
    word_len = read_word(word, MAX_WORD_LEN+1);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }
  if (fclose(stdin) == EOF)
    perror(argv[1]);
  if (fclose(stdout) == EOF)
    perror(argv[2]);
}

void clear_line(void)
{
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int padding, gaps_needed, extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      putchar(line[i]);
    else {
      /* each gap between 2 words could have more than 1 space */
      gaps_needed = num_words - 1;
      padding = extra_spaces / gaps_needed;
      spaces_to_insert = 1 + padding;

      for (j = 1; j <= spaces_to_insert; j++)
        putchar(' ');
      extra_spaces -= padding;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line(void)
{
  if (line_len > 0)
    puts(line);
}

int read_char(void)
{
  int ch = getchar();
  if (ch == '\r' || ch == '\n' || ch == '\t')
    return ' ';
  return ch;
}

int read_word(char *word, int len)
{
  int ch, pos = 0;

  while ((ch = read_char()) == ' ')
    ;
  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char();
  }
  if (pos == len)
    word[pos - 1] = '*';

  word[pos] = '\0';
  return pos;
}

void invocation_error(char *program, char *usage)
{
  fprintf(stderr, "Usage: %s %s\n", program, usage);
  exit(1);
}

void memory_error(char *file, unsigned int line, const char *func)
{
  fprintf(stderr, "Memory Allocation Failure: %s:%d in function %s()\n", file, line, func);
  exit(EXIT_FAILURE);
}

void print_error(char *program, char *s2)
{
  fprintf(stderr, "%s: %s: %s\n", program, s2, strerror(errno));
}
void exit_error(char *program, char *s2)
{
  print_error(program, s2);
  exit(EXIT_FAILURE);
}
int is_file_name_error(int e)
{
  if ((strcmp(strerror(e), "No such file or directory") == 0) ||
      (strcmp(strerror(e), "Is a directory") == 0) ||
      (strcmp(strerror(e), "File name too long") == 0))
    return 1;
  return 0;
}


