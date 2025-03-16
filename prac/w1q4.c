#include <stdio.h>

int main() {
    int num1, num2, reversedNum = 0, originalNum, remainder;

    printf("Enter an integer: ");
    scanf("%d", &num1);

    originalNum = num1;

    while (num1 != 0) {
        remainder = num1 % 10;
        reversedNum = reversedNum * 10 + remainder;
        num1 /= 10;
    }

    if (originalNum == reversedNum) {
        printf("%d is the reverse.\n", originalNum);
    } else {
        printf("%d is not the reverse.\n", originalNum);
    }

    return 0;
}
