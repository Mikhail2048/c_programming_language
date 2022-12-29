#include<stdio.h>

/* 
 *Indicates we are in the multiline comment now 
 */
#define INSIDE_MULTILINE_COMMENT 2

/* 
 * Indicates we are in the single comment now 
 */
#define INSIDE_SINGLE_COMMENT 1

/*
 * Indicates, that now we are inside the string
 */
#define INSIDE_STRING 3

/* 
 * Indicates we are not in the comment and string now 
 */
#define OUTSIDE_COMMENT_AND_STRING 0

/*
 * Max resulting programm size in characters 
 */
#define MAX_OUTPUT_PROGRAMM_SIZE 10000

/* 
 * If current symbol is NOT a part of a comment, typically
 * used to determine is the currenct symbol - reversed slash (\)
 * just a symbol, or an end of a comment 
 */
#define NOT_PART_OF_COMMENT 0

/* 
 * The same as doc as for NOT_PART_OF_COMMENT, but this macros means 
 * that last symbol IS a part of a comment 
 */
#define PART_OF_COMMENT 1

int state = OUTSIDE_COMMENT_AND_STRING;
int current_char_state = NOT_PART_OF_COMMENT;
int output_programm_index = 0;
char output_programm[MAX_OUTPUT_PROGRAMM_SIZE];

extern int not_inside_comment(void);
extern void handle_inside_comment(int previous_char, int currrenct_char);
extern void handle_outside_comment(int previous_char, int currrenct_char);

int main() {

    int prev, c;

    prev = c = getchar();

    if (prev == EOF) {
        return 0;
    }

    while ((c = getchar()) != EOF) {
        if (not_inside_comment()) {
            handle_outside_comment(prev, c);
        } else {
            handle_inside_comment(prev, c);
        }
        prev = c;
    }

    printf("%s\n", output_programm);

    return 0;
}

void handle_inside_comment(int previous_char, int currrenct_char) {
    // Ended single line comment
    if (currrenct_char == '\n' && state == INSIDE_SINGLE_COMMENT) {
        state = OUTSIDE_COMMENT_AND_STRING;
    // Ended multiline comment
    } else if (previous_char == '*' && currrenct_char == '/') {
        state = OUTSIDE_COMMENT_AND_STRING;
        current_char_state = PART_OF_COMMENT;
    }
}

void handle_outside_comment(int previous_char, int currrenct_char) {
    if (state == INSIDE_STRING) {
        if (currrenct_char == '\"') {
            state = OUTSIDE_COMMENT_AND_STRING;
        }
        output_programm[output_programm_index++] = previous_char;
    } else {
        // Single comment encountered
        if (currrenct_char == '/' && previous_char == '/') {
            state = INSIDE_SINGLE_COMMENT;
        // Multiline comment encountered
        } else if (currrenct_char == '*' && previous_char == '/') {
            state = INSIDE_MULTILINE_COMMENT;
        } else {
            if (currrenct_char == '\"') {
                state = INSIDE_STRING;
            }
            if (current_char_state != PART_OF_COMMENT) {
                output_programm[output_programm_index++] = previous_char;
            } else {
                current_char_state = NOT_PART_OF_COMMENT;
            }
        }
    }
}

int not_inside_comment(void) {
    return state != INSIDE_MULTILINE_COMMENT && state != INSIDE_SINGLE_COMMENT;
}