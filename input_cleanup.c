#include<stdio.h>

#define MAX_AMOUNT_OF_WHITESPACES 10 /* Max amout of whitespaces at the end to trim */
#define MAX_LINE_SIZE 100
#define MAX_TOTAL_LINES 5000 /* Max amount of characters in all lines, including new line characters */

void append_at_the_end_from_index(char[], char[], int);
int read_line(char buffer[]);

int main() {
    char line[MAX_LINE_SIZE];
    char lines_total[MAX_TOTAL_LINES];

    int read_characters, writable_index_total = 0;
    
    while ((read_characters = read_line(line)) != -1) {
        if (read_characters != 0) {
            append_at_the_end_from_index(line, lines_total, writable_index_total);
            writable_index_total += read_characters;
            lines_total[writable_index_total++] = '\n';
        }
    }

    printf("%s\n", lines_total);

    return 0;
}

/*
 * Reads the input from stdin 
 *
 * Returnrs: the amount of characters read, or -1 if EOF encountered
 */
int read_line(char buffer[]) {
   int c, tmp_buffer_index = 0, index = 0;
   char tmp_whitespace_buffer[MAX_AMOUNT_OF_WHITESPACES]; // all whitespace characters at the end that we have met so far
 
   while ((c = getchar()) != EOF && c != '\n') {
      if (c == ' ' || c == '\t') {
         tmp_whitespace_buffer[tmp_buffer_index++] = c;
         tmp_whitespace_buffer[tmp_buffer_index] = '\0';
      } else {
         // check is there a buffer to write first
         if (tmp_buffer_index != 0) {
            append_at_the_end_from_index(tmp_whitespace_buffer, buffer, index);
            tmp_whitespace_buffer[0] = '\0';
            index += tmp_buffer_index;
            tmp_buffer_index = 0;
         }
         buffer[index++] = c;
      }
   }

   if (c == EOF) {
      return -1;
   }

   return index; 
}

// from_index - inclusive
void append_at_the_end_from_index(char from[], char to[], int from_index) {
   int start = 0;

   while (from[start] != '\0') {
      to[from_index++] = from[start++];
   }
}