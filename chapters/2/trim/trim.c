#ifndef TRIM_C
#define TRIM_C

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stringutils.h"

#ifndef STATE
#define NOT_TRIMMED 0
#define LEFT_TRIMMED 1
#define RIGHT_TRIMMED 2
#endif

char* trim(const char* src) {
    int right_indx = strlen(src) - 1, 
        left_indx = 0,
        state = NOT_TRIMMED;

    for (; left_indx < right_indx;) {
        if (state != LEFT_TRIMMED) {
            if (is_whitespace(*(src + left_indx))) {
                left_indx++;
            } else {
                if (state != RIGHT_TRIMMED) {
                    state = LEFT_TRIMMED;
                } else {
                    break;
                }
            }
        } 
        if (state != RIGHT_TRIMMED) {
            if (is_whitespace(*(src + right_indx))) {
                right_indx--;
            } else {
                if (state != LEFT_TRIMMED) {
                    state = RIGHT_TRIMMED;
                } else {
                    break;
                }
            }
        }
    }
    int result_size = right_indx - left_indx + 1;
    char* result = (char*) malloc(sizeof(char) * result_size);
    memcpy(result, src, (size_t) result_size);
    return result;
}

void printString(char *arr) {
    while (*arr != '\0') {
        printf("%c", *arr);
        arr++;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    printString(trim(" \t \n  alesha    \n "));
    return 0;
}

#endif