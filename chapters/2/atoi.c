#include<stdio.h>
#include<string.h>
#include<math.h>

/*
 * 1 if true, 0 if false
 */
extern int atoi(char arr[]);

/*
 * 1 if true (passed char is digit, i.e from '0' to '9'), 0 if false
 */
extern int is_digit(char);

/*
 * Converts char to its numerical value. Not confused with ASCII value. 
 * 
 * '0' --> 0
 * '1' --> 1
 * '2' --> 2
 * 'c' --> -1
 * '\n' --> -1
 * 
 * return -1 if char canont be treated as int (i.e. char is not in ASCII range '0' to '9') 
 */
extern int char_to_digit(char);

int main() {
  int value = atoi("9123200");

  printf("Value : %d\n", value);
}

int atoi(char arr[]) {
  int total = 0;
  int arr_size  = strlen(arr);

  for (int i = 0; i < arr_size; i++) {
    int element = arr[arr_size - (i + 1)];    
    if (!is_digit(element)) {
        return -1;
    }
    total += char_to_digit(element) * pow(10, i);
  }

  return total;
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int char_to_digit(char c) {
    if (is_digit(c)) {
        return c - '0';
    }
    return -1;
}