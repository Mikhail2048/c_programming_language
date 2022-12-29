#include<stdio.h>
#include <stdlib.h>
 
/*
 * Max line size in characters
 */
#define MAX_INPUT_SIZE 1000

#define LINE_LENGTH_LIMIT 30

char current_line[MAX_INPUT_SIZE];
int index_ = 0;
int amount_of_words_inside_line = 0;

void print_until_index(int k) {
    for (int i = 0; i < k; i++) {
        printf("%c", current_line[i]);
    }
    printf("[%d]\n", k);
}

void copy_word_to_the_beggining(int from_index, int to_index) {
    int i = 0;
    for (; from_index < to_index; from_index++) {
        current_line[i++] = current_line[from_index];
    }
    current_line[i++] = ' ';
    index_ = i;
    amount_of_words_inside_line = 1;
}

void print_line_and_adjust_index(int current_word_len) {

    int index_of_last_word_start = index_ - current_word_len;

    if (abs(index_ - LINE_LENGTH_LIMIT) > abs(index_of_last_word_start - LINE_LENGTH_LIMIT) && amount_of_words_inside_line != 1) {
        print_until_index(index_of_last_word_start);
        copy_word_to_the_beggining(index_of_last_word_start, index_);
        // copy unptinted word to the beginning of the string here
    } else {
        print_until_index(index_);
        index_ = 0;
        amount_of_words_inside_line = 0;
    }
}

int is_whitespace(int c) {
    return c == '\n' || c == ' ' || c == '\t';
}

int main() {
    int c;
    int current_word_len = 0;
    while ((c = getchar()) != EOF) {
        if (index_ >= LINE_LENGTH_LIMIT && is_whitespace(c)) {
            if (index_ == LINE_LENGTH_LIMIT) {
                print_until_index(index_);
                index_ = 0;
                amount_of_words_inside_line = 0;
            } else {
                print_line_and_adjust_index(current_word_len);
            }
            current_word_len = 0;
        } else if (is_whitespace(c) && current_word_len != 0) {
            current_line[index_++] = ' ';
            current_word_len = 0;
        } else {
            current_line[index_++] = c;
            current_word_len++;
            amount_of_words_inside_line++;
        }
    }
    if (index_ != 0) {
        print_until_index(index_);
    }
    return 0;
}