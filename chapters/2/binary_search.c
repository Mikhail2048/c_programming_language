#include<stdio.h>
#include<stdlib.h>

#define SIZEOF_ARRAY(arr) sizeof(arr) / sizeof(arr[0])

extern int do_binary_search(int val, int array[], int);
extern int arr_length(int[]);

int main() {
    int a[7] = {3, 4, 5, 6, 7, 8, 9};
    printf("1. Result: %d\n", do_binary_search(4, a, SIZEOF_ARRAY(a)));

    int b[7] = {3, 4, 5, 6, 7, 8, 9};
    printf("2. Result: %d\n", do_binary_search(1, b, SIZEOF_ARRAY(b)));

    int c[10] = {3, 4, 5, 6, 7, 8, 9, 11, 15, 19};
    printf("3. Result: %d\n", do_binary_search(19, c, SIZEOF_ARRAY(c)));

    int d[7] = {3, 4, 5, 6, 7, 8, 9};
    printf("4. Result: %d\n", do_binary_search(8, d, SIZEOF_ARRAY(d)));

    return 0;
}

int do_binary_search(int val, int array[], int arr_size) {
    int left = 0;
    int right = arr_size;
    int middle_index;

    while (abs(right - left) > 1) {
        middle_index = (right + left) / 2;
        if (array[middle_index] > val) {
            right = middle_index - 1;
        } else {
            left = middle_index;
        }
    }

    if (array[left] == val) {
        return left;
    }

    if (array[right] == val) {
        return right;
    }

    return -1;
}