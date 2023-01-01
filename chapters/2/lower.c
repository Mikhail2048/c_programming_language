#include<stdio.h>
/*
 * Turn letter to lowercase. If the letter already lowercase, the char returned unchanged.
 * Returns -1 if the passed char is not a representation of a character
 * 
 * 'c' --> 'c'
 * 'q' --> 'q'
 * 'Y' --> 'y'
 * 'R' --> 'r'
 * '\\' --> -1
 * '~' --> '-1'
 *
 */
extern int lower(char);

int main() {
   int minus_one = lower('5');
   int lower_p = lower('p');
   int lower_x = lower('X');

   printf("minus_one : %d\nlower_p : %c\nlower_x : %c\n", minus_one, lower_p, lower_x);
}

int lower(char c) {
    if (c > 'a' && c < 'z') {
        return c;
    }

    if (c > 'A' && c < 'Z') {
        return c + 32;
    }

    return -1;
}