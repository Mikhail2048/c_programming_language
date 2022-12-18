#include<stdio.h>

#ifndef MAX_LINE_SIZE
#define MAX_LINE_SIZE 1000 /* Max line size */
#endif

/* 
 Return -1 if there is not input and the array is empty
 Otherwise fill array with data and return the amount of elements filled.
 If needed, the array will be increased.
*/
int read_line_stdin(char[]);

/*
 Copying the src array into target array, Increaseing target array if needed
 size - how much elements to copy
*/
void array_copy(char src[], char target[], int size);

main() {

    char longest_line[MAX_LINE_SIZE];
    char current_line[MAX_LINE_SIZE];
    int cur_line_length, max_line_length;
    
    while ((cur_line_length = read_line_stdin(current_line)) != -1) {
        if (cur_line_length > max_line_length) {
            array_copy(current_line, longest_line, cur_line_length);
            max_line_length = cur_line_length;
        }
    }

    printf("\nThe longest line is %d characters long. The string itself is : \n\n%s\n", max_line_length, longest_line);
}

void array_copy(char src[], char target[], int size) {
    for (int i = 0; src[i] != '\0' && i < size; i++) {
        target[i] = src[i];
    }
}

int read_line_stdin(char buffer[]) {
    int c, index = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        buffer[index] = c;
        index++;
    }
    if (index == 0) 
        return -1;
    return index;
}