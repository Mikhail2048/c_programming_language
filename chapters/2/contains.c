#include<stdio.h>

extern int contains(char src[], char trgt[]);

enum boolean {
    FALSE = 0,
    TRUE
};

int main(int argc, char const *argv[]) {
    char src[] = "102391238801239182748243";
    char trgt[] = "8802";

    printf("Contains : %s\n", contains(src, trgt) ? "true" : "false");
    return 0;
}

int contains(char src[], char trgt[]) {
    if (src[0] == '\0' || trgt[0] == '\0') {
        return FALSE;
    }

    int trgt_index, i;

    trgt_index = i = 0;

    while (src[i] != '\0') {
        if (src[i++] == trgt[trgt_index]) {
            trgt_index++;
            if (trgt[trgt_index] == '\0') {
                return TRUE;
            }
        } else {
            trgt_index = 0;
        }
    }

    return FALSE;
}