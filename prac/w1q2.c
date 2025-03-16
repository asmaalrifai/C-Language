#include <stdio.h>

int main() {
    char char1, char2, char3;

    printf("Enter three characters: ");
    scanf(" %c %c %c", &char1, &char2, &char3);

    char highChar;

    if (char1 > char2) {
        if (char1 > char3) {
            highChar = char1;
        } else {
            highChar = char3;
        }
    } else {
        if (char2 > char3) {
            highChar = char2;
        } else {
            highChar = char3;
        }
    }

    printf("The character with the highest ASCII value is: %c\n", highChar);

    return 0;
}
