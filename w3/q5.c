#include <stdio.h>
#include <string.h>

void toUpperCase(char* str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;  // Convert lowercase to uppercase using ASCII values
        }
        str++;
    }
}

int main() {
    char text[] = "Hello, World!";
    printf("Original String: %s\n", text);
    toUpperCase(text);
    printf("Uppercase String: %s\n", text);

    return 0;
}
