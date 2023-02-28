#include<stdbool.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int indexOf(char* string, char* substring) {
    char* current = substring;
    int index = 0, start_match = -1;
    while (*string != '\0') {
        if (*current == '\0') {
            break;
        }
        if (*current != *string) {
            current = substring;
            start_match = -1;
        } else {
            if (start_match == -1) {
                start_match = index;
            }
            current++;
        }
        index++;
        string++;
    }
    if (*current == '\0') {
        return start_match;
    }
    return -1;
}

char* replace(char* string, char* src, char* target) {

    int string_length = strlen(string);

    int index = indexOf(string, src);

    char* result = string;
    
    if (index == -1) {
        goto label;
    } else {
        int target_length = strlen(target);
        int src_length = strlen(src);

        if (src_length == target_length) {
            memcpy(result + index, target, target_length);
            goto label;
        } else if (src_length > target_length) {
            int diff = src_length - target_length;
            result = realloc(result, sizeof(char) * (string_length - diff));
            memcpy(result, string, index);
            memcpy(result + index, target, target_length);
            memcpy(result + index + target_length, string, string_length - (src_length + index));
            goto label;
        } else {
            int diff = target_length - src_length;
            result = realloc(result, sizeof(char) * (string_length + diff));
            memcpy(result, string, index);
            memcpy(result + index, target, target_length);
            memcpy(result + index + target_length, string, string_length - (target_length + index));
        }
    }

    label:
        return result;
}

bool contains(char* src, char* dest) {

    char* current = dest;

    do_contains:

        if (*current == '\0') {
            return true;
        }

        if (*src != '\0') {
            if (*src == *current) {
                current++;
            } else {
                current = dest;
            }
            src++;
        } else {
            return false;
        }

    goto do_contains;
}

int main(int argc, char const **args) {

    //contains
    assert(contains("alesha", "a"));
    assert(contains("alesha", "alesha"));
    assert(contains("alesha", "esha"));
    assert(contains("alesha", "alesh"));
    assert(!contains("alesha", "aleshaa"));
    assert(!contains("alesha", "b"));

    //indexOf
    printf("indexOf(\"abcdef\", \"ift\") = %d\n", indexOf("abcdef", "ift"));
    printf("indexOf(\"abc\", \"abc\") = %d\n", indexOf("abc", "abc"));
    printf("indexOf(\"abcdefg\", \"def\") = %d\n", indexOf("abcdefg", "def"));
    printf("indexOf(\"abcdefg\", \"a\") = %d\n", indexOf("abcdefg", "a"));
    printf("indexOf(\"abcdefg\", \"abcdef\") = %d\n", indexOf("abcdefg", "abcdef"));
    printf("indexOf(\"abcdefg\", \"abcdefg1\") = %d\n", indexOf("abcdefg", "abcdefg1"));
    return 0;
}
