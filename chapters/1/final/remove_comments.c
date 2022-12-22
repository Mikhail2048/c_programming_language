#include<stdio.h>

#define INSIDE_MULTILINE_COMMENT 2 /* Indicates we are in the multiline comment now */
#define INSIDE_SINGLE_COMMENT 1 /* Indicates we are in the single comment now */
#define OUTSIDE_COMMENT 0 /* Indicates we are not in the comment now */

extern int is_inside_comment(int state);

int main() {

    int prev, c, state = OUTSIDE_COMMENT;

    int prev = c = getchar();

    if (prev == EOF) {
        return 0;
    }

    while ((c = getchar()) != EOF) {
        if ()
        // Single comment encountered
        if (c == '/' && prev == '/') {
            state = INSIDE_SINGLE_COMMENT;
        // Multiline comment encountered
        } else if (c == '*' && prev == '/') {
            state = INSIDE_MULTILINE_COMMENT;
        } else {
            putchar(prev);
        }
    }

    return 0;
}

int is_inside_comment(int state) {
    return state == INSIDE_MULTILINE_COMMENT || state == INSIDE_SINGLE_COMMENT;
}