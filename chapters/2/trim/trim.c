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

char* trim(char* src) {
    int len = strlen(src),
        right_indx = len - 1, 
        left_indx = 0,
        state = NOT_TRIMMED;

    for (; left_indx < right_indx; left_indx++, right_indx--) {
        if (state != LEFT_TRIMMED) {
            if (is_whitespace(*(src + left_indx))) {
                *(src + left_indx) = '\0';
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
                *(src + right_indx) = '\0';
            } else {
                if (state != LEFT_TRIMMED) {
                    state = RIGHT_TRIMMED;
                } else {
                    break;
                }
            }
        }
    }
    return src + left_indx;
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