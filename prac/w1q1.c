#include <stdio.h>

int main() {
    int input;
    int sum = 0;

    printf("Enter values .\n");

    while (1) {
        printf("Enter a value: ");
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        sum += input;
    }

    printf("The sum of the entered values is: %d\n", sum);

    return 0;
}
