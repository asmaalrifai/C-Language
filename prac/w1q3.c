#include <stdio.h>

int main() {
    char input;
    char charArray[6]; //max is 6
    int index = 0;
    int display = 0;

    printf("Enter characters. Enter 'x' to stop and 'c' to display the array:\n");

    while (1) {
        printf("Enter a character: ");
        scanf(" %c", &input);

        if (input == 'x') {
            break;  // stop
        } else if (input == 'c') {
            display = 1;
            break;  // display
        }

        charArray[index] = input;
        index++;

        if (index >= sizeof(charArray)) {
            printf("Array is full.\n");
            break;
        }
    }

    if (display) {
        printf("Array content: ");
        for (int i = 0; i < index; i++) {
            printf("%c", charArray[i]);
        }
        //printf("%s", charArray);
        printf("\n");
    } else {
        printf("You entered 'x' before 'c'. Array not displayed.\n");
    }

    return 0;
}
