#include<string.h>
#include<stdio.h>
#include<math.h>

extern long int htoi(char[]);
extern int to_10_radix(char);

int main(void) {
    long val = htoi("0x00FF");
    printf("Result : %ld\n", val);
}

long int htoi(char hex_string[]) {

    int c, int_val;

    int size = strlen(hex_string);

    for (int i = 0; i < size; i++) {
        c = hex_string[size - (i + 1)];
        if (c == 'X' || c =='x') {
            break;
        }
        int_val += to_10_radix(c) * pow(16, i);
    }
    return int_val;
}

int to_10_radix(char c) {

    if (c >= '0' && c <= '9') return c - '0';

    if (c >= 'A' && c <= 'F') return c - 55;

    if (c >= 'a' && c <= 'f') return c - 87;
}