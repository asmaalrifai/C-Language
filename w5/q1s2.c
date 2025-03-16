#include <stdio.h>

#define SIZE 5

int* addArrays(int a[SIZE], int b[SIZE]) {
    static int sum[SIZE];
    for (size_t i = 0; i < SIZE; i++) {
        sum[i] = a[i] + b[i];
    }
    return sum;
}

int main() {
    int a[SIZE] = {1, 2, 3, 4, 5};
    int b[SIZE] = {6, 7, 8, 8, 9}; // Added the missing semicolon here
    int* c = addArrays(a, b);
    for (size_t i = 0; i < SIZE; i++) {
        printf("%d ", c[i]); // Added a space for readability
    }
    return 0;
}
