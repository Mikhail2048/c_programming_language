#include<stdio.h>

#ifndef MAX_LINE_LENGTH
#define MAX_LINE_LENGTH 1000 /* Max size of line in characters */    
#endif 


int read_line_reversed(char[]);
void copy(char from[], char to[], int copy_from_index);

int main() {
    char buffer[MAX_LINE_LENGTH];
    int start_index = read_line_reversed(buffer);
    char result_arr[MAX_LINE_LENGTH - start_index];
    copy(buffer, result_arr, start_index);
    printf("%s\n", result_arr);
}

void copy(char from[], char to[], int copy_from_index) {
    int i = 0;
    for (; copy_from_index < MAX_LINE_LENGTH; copy_from_index++) {
        to[i++] = from[copy_from_index];
    }
}

int read_line_reversed(char buffer[]) {
    int cur_character, i = 0;

    while ((cur_character = getchar()) != EOF && cur_character != '\n') {
        buffer[MAX_LINE_LENGTH - (i + 1)] = cur_character;
        i++;
    }

    return MAX_LINE_LENGTH - i;
}