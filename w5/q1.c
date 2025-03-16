#include <stdio.h>

#define ARRAY_SIZE 5

void sumArrays(const int* arr1, const int* arr2, int* result) {
    static int tempResult[ARRAY_SIZE]; 

    for (int i = 0; i < ARRAY_SIZE; i++) {
        tempResult[i] = arr1[i] + arr2[i];
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = tempResult[i];
    }
}

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {5, 6, 7, 8, 1};
    int result[ARRAY_SIZE];

    sumArrays(array1, array2, result);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
