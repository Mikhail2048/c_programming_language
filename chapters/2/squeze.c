#include<stdio.h>

extern void squeze(char s[], char t);

int main(int argc, char const *argv[]) {

    char s[] = "0123123";

    squeze(s, '1');

    printf("Result : %s\n", s);

    return 0;
}

void squeze(char s[], char t) {
    int i, j;

    i = j = 0;

    while (s[i] != '\0') {
        if (s[i] != t) {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}
