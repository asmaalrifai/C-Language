#include <stdio.h>

#define ARRAY_SIZE 5

// Function to calculate the sum of elements in two arrays.
void sumArrays(const int* array1, const int* array2, int* result) {
    static int tempResult[ARRAY_SIZE]; // Static array to store the result.
    static int initialized = 0; // Static flag to ensure initialization only once.

    if (!initialized) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            tempResult[i] = array1[i] + array2[i];
        }
        initialized = 1;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = tempResult[i];
    }
}

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {5, 4, 3, 2, 1};
    int result[ARRAY_SIZE];

    // Calculate the sum of the two arrays and store it in the result array.
    sumArrays(array1, array2, result);

    // Print the result array.
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
