#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MAX_ARR_LEN
int MAX_ARRAY_LENGTH = 1000;
#endif

#ifndef REG_EXP_STATES
#define IN_EXPANSION 1 /* means that we are currently expaninding something already */
#define OUT_EXPANSION 0 /* means that we are currently expaninding something already */
#endif

extern int is_whitespace(int symbol);
extern int is_alphabetic_character(int symbol);
extern int expand_segment(int from, int to, char* target, int target_start_index);
extern void assert_input_output(char input[], char output[]);
extern char* expand(char regexp[]);

void assert_input_output(char input[], char output[]) {
    char* ar_pointer = expand(input);

    size_t execpted_out_len = strlen(output);

    printf("Output expected : ");

    for (int i = 0; i < execpted_out_len; i++) {
        printf("%c", output[i]);
    }

    printf("\nOutput real     : ");

    for (int i = 0; i < MAX_ARRAY_LENGTH && *(ar_pointer + i) != '\0'; i++) {
        printf("%c", *(ar_pointer + i));
    }

    printf("\n\n");

    free(ar_pointer);
}


int main() {
    assert_input_output("-ab-d", "-abcd");
    assert_input_output("    -Z-atty", "-Z[\]^_`atty");
    assert_input_output("a-f0-4k", "abcdef01234k");
    assert_input_output("q+--1", "q+,-1");
}

/*
 Examples:
 [-ab-d] --> [-abcd]
 [-Z-atty] --> [-Z[\]^_`atty]
 [a-f0-4k] --> [abcdef01234k]
 [-wqeqwe] --> [-wqeqwe]
 [qr--1] --> [qr-./01]
*/
char* expand(char regexp[]) {
    int i;

    char* result_array = malloc( sizeof(char) * MAX_ARRAY_LENGTH );

    //skip whitespaces
    for (i = 0; regexp[i] != '\0' && is_whitespace(regexp[i]); i++)
        ;

    if (regexp[i] == '\0') {
        *result_array = '\0';
        return result_array;
    } else {
        *result_array = regexp[i++];
    }

    int res_array_index = 1, 
        element,
        state = OUT_EXPANSION;

    for (; (element = regexp[i]) != '\0';i++) {
        
        if (element == '-') {
            if (state == OUT_EXPANSION) {
                state = IN_EXPANSION;
            } else {
                res_array_index = expand_segment(regexp[i - 2], element, result_array, res_array_index);
                state = OUT_EXPANSION;
            }
        } else {
            if (state == OUT_EXPANSION) {
                *(result_array + res_array_index) = element;
                res_array_index++;
            } else {
                res_array_index = expand_segment(regexp[i - 2], element, result_array, res_array_index);
                state = OUT_EXPANSION;
            }
        }
    }

    if (element == '-') {
        *(result_array + res_array_index) = '-';
        res_array_index++;
    }
    *(result_array + res_array_index) = '\0';
    return result_array;
}

int expand_segment(int from, int to, char* target, int target_start_index) {
    if (from > to) {
        perror("Error : cannot compile the regexp - the start symbol ascii is larger the end symbol ascii");
        exit(1);
    }
    from++;
    for (; from <= to; from++) {
        *(target + target_start_index) = from;
        target_start_index++;
    }

    return target_start_index;
}

int is_whitespace(int symbol) {
    switch (symbol) {
        case ' ' : 
        case '\t':
        case '\n': 
            return 1;
        default:
            return 0;
    }
}
