#include <stdio.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 1000

int main() {
    FILE *file;
    char filename[MAX_FILENAME_LENGTH];
    char buffer[MAX_BUFFER_SIZE];

    // Prompt user for the file name
    printf("Enter the file name to read: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Contents of the file '%s':\n", filename);

    // Read and print the contents of the file
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}
