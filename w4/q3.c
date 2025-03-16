#include <stdio.h>


void sum(int num1, int num2, int* result) {
    *result = num1 + num2;
}

int main() {
    int number1 = 5;
    int number2 = 7;
    int sumResult;

   
    sum(number1, number2, &sumResult);

   
    printf("The sum of %d and %d is %d\n", number1, number2, sumResult);

    return 0;
}
