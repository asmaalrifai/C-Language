#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    // Declare a pointer to an integer and initialize it to the beginning of the array.
    int* ptr = arr;

    // Use a loop to go through the array and increment each element by 1.
    for (int i = 0; i < length; i++) {
        (*ptr)++; // Increment the value at the current position.
        ptr++;    // Move the pointer to the next element.
    }

    // Print the updated array.
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
