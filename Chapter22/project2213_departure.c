// Modify Programming Project 8 from Chapter 5 so that the program obtains departure and
// arrival times from a file named flights.dat. Each line of the file will contain a departure
// time followed by an arrival time, with one or more spaces separating the two. Times
// will be expressed using the 24-hour clock. For example, here's what flights.dat might
// look like if it contained the flight information listed in the original project. 

// 8:00  10:16
// 9:43  11:52
// 11:19  13:31
// 12:47  15:00
// 14:00  16:08
// 15:45  17:55
// 19:00  21:20
// 21:45  23:58	

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/stat.h>

#define DATA_ERROR(f, l, s)                                               \
        do {                                                              \
          fprintf(stderr, "Invalid data  %s:%ld  '%s'\n", (f), (l), (s)); \
          data_error = true;                                              \
        } while (0)

#define TIME_STR_SIZE 6
#define FILE_PATH "flights.dat"

void find_closest_flight(int, int *, int *);
void print_am_pm(int);
int get_valid_input(void);
int to_minutes(char *);
bool is_format_valid(char *);
void convert(char *, int *, int *);

int main(void)
{
  int departure, arrival;

  /* * pass in as minutes since midnight */
  find_closest_flight(get_valid_input(), &departure, &arrival);

  /*
   * display the user's answer
   */
  printf("Closest departure time is ");
  print_am_pm(departure);
  printf(", arriving at ");
  print_am_pm(arrival);
  printf("\n");

  return 0;
}

void find_closest_flight(int requested_departure, int *departure_time, int *arrival_time)
{
  int diff, m;
  FILE *fp;
  char line[TIME_STR_SIZE * 2 + 1];
  char d[TIME_STR_SIZE], a[TIME_STR_SIZE];
  bool read_error = false, data_error = false;
  size_t l;

  if ((fp = fopen(FILE_PATH, "r")) == NULL) {
    perror(FILE_PATH);
    exit(EXIT_FAILURE);
  }
  int minimum_difference = 23*60+59;
  for (l = 0;fgets(line, sizeof(line), fp) != NULL; l++) {
    sscanf(line, "%s %s", d, a);
    if ((m = to_minutes(d)) == -1) {
      DATA_ERROR(FILE_PATH, l + 1, d);
      break;
    }
    diff = abs(requested_departure - m);
    if (diff < minimum_difference)  {
      minimum_difference = diff;
      *departure_time = m;
      if ((m = to_minutes(a)) == -1) {
        DATA_ERROR(FILE_PATH, l + 1, a);
        break;
      }
      *arrival_time   = m;
    }
  }
  if (!feof(fp) || ferror(fp)) {
    if (!data_error)  {
      perror(FILE_PATH);
      read_error = true;
      errno = 0;
    }
  }
  if (feof(fp) && l == 0) {
    fprintf(stderr, "Empty data file: %s\n", FILE_PATH);
    data_error = true;
  }

  if (fclose(fp) == EOF || read_error || data_error) {
    if (!data_error && !read_error)
      perror(FILE_PATH);
    exit(EXIT_FAILURE);
  }
}

int to_minutes(char *s)
{
  int hour, minute;
  if (is_format_valid(s)) {
    convert(s, &hour, &minute);
    if (hour < 24 && minute < 60)
      return (hour * 60) + minute;
  }
  return -1;
}

void print_am_pm(int minutes_since_midnight)
{
  int hours = minutes_since_midnight / 60;
  int minutes = minutes_since_midnight % 60;
  char meridian[] = "AM";

  if (hours >= 12) {
    meridian[0] = 'P';
    hours -= 12;
  }
  if (hours == 0)
    hours = 12;

  printf("%d:%.2d %s", hours, minutes, meridian);

}

int get_valid_input(void)
{
  int i, ch, hour, minute;
  char input[TIME_STR_SIZE] = {'\0'};

  for (;;) {
    printf("Request departure time: (e.g. 21:23): ");
    /* swallow spaces */
    while (isspace(ch = getchar()))
        ;

    /* fill in the input buffer,
     * and consume any remaining input
     * on stdin including the newline.
     * That way, we don't get any double prompts
     * should we have to re-prompt after bad input
     */
    for (i = 0; ch != '\n'; ch = getchar())
      if (i < TIME_STR_SIZE)
        input[i++] = ch;

    input[i] = '\0';
    if (is_format_valid(input)) {
      convert(input, &hour, &minute);
      if (hour < 24 && minute < 60)
        return (hour * 60) + minute;
    }

    fprintf(stderr, "Invalid Input: '%s'\n", input);
  }
}
bool is_format_valid(char *s)
{
  size_t i, len = strlen(s);
  int d;
  if (!len)
    return false;

  for (d = -1, i = 0; i < len; i++)  {
    if (d < 0 &&               /* No delimiter found yet */
        s[i] == ':') {         /* First instance of delimiter */
      d = i;                   /* Can't follow this branch anymore:
                                * any other copies of ':' will see isdigit().
                                */
      if (d < 1 || d > 2)      /* possible positions */
        return false;
    } else if (!isdigit(s[i]))
      return false;
  }

  if (d == -1 && len > 2)  /* if there's no delimiter, */
    return false;          /* there can only be a 1 or 2 digit hour */

  if (d == (int)len - 1)   /* delimiter is at the end */
    return false;

  return true;
}
void convert(char *s, int *hour, int *minute)
{
  char h[3] = {'\0'}, *delimiter;

  if ((delimiter = strchr(s, ':'))) {
    strncpy(h, s, delimiter - s);
    *hour   = atoi(h);
    *minute = atoi(delimiter + 1);
  } else {
    *hour   = atoi(s);
    *minute = 0;
  }
}
