#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int* i_sum_up(const char* integer_string) {

    int* result = malloc(sizeof(int)), 
        i = 1,
        ascii_char = *integer_string,
        str_len = strlen(integer_string);

    while (ascii_char != '\0') {
        if (ascii_char >= 48 && ascii_char <= 57) {
            *result += (ascii_char - 48) * pow(10, str_len - i);
        } else {
            printf("Provided argument is not an integer : %c\n", ascii_char);
            exit(1);
        }
        i++;
        ascii_char = *(++integer_string);
    }

    return result;
}

char* itoa(int value) {
    
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Error: Provided not 1 parameter\n");
        return 0;
    }

    const char* argument = argv[1];
    int* result = i_sum_up(argument);
    printf("Result : %d\n", *result);
}