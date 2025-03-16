#include <stdio.h>


typedef int (*ArithmeticFunction)(int, int);

// Function to add two numbers.
int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 10;
    int b = 5;

    ArithmeticFunction operation;

    operation = add;
    int result = operation(a, b);
    printf("a + b = %d\n", result);
}