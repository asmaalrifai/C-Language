#include <stdio.h>
#include <string.h>

int main() {
    // Define a character array to store the user's name
    char name[100]; // Assuming the name won't exceed 99 characters

    // Prompt the user to enter their name
    printf("Please enter your name: ");

    // Read the user's input as a string
    fgets(name, sizeof(name), stdin);

    // Remove the newline character from the end of the input
    name[strcspn(name, "\n")] = '\0';

    // Display a greeting with the user's name
    printf("Hello, %s! Nice to meet you.\n", name);

    return 0;
}
