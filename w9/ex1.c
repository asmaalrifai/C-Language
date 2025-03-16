#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "keyboard_input.txt";
    char input;

    // Open the file for writing
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Enter text (press 'q' to quit):\n");

    do {
        // Read a character from the keyboard
        input = getchar();

        // Write the character to the file
        fputc(input, file);

    } while (input != 'q');  // Terminate when 'q' is entered

    // Close the file
    fclose(file);

    printf("Text input saved to %s.\n", filename);

    return 0;
}
