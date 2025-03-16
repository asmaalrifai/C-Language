#include <stdio.h>
#include <stdlib.h>

void removeLineWithTempFile(const char *filename, int lineNumber) {
    FILE *inputFile, *tempFile;
    char buffer[1024];
    int currentLine = 1;

    // Open the input file for reading
    inputFile = fopen(filename, "r");

    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return;
    }

    // Open a temporary file for writing
    tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL) {
        fclose(inputFile);
        printf("Error opening the temporary file.\n");
        return;
    }

    // Copy lines to the temporary file, excluding the specified line
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        if (currentLine != lineNumber) {
            fputs(buffer, tempFile);
        }
        currentLine++;
    }

    // Close the input file
    fclose(inputFile);

    // Close and remove the original file
    remove(filename);

    // Rename the temporary file to the original file name
    rename("temp.txt", filename);

    // Close the temporary file
    fclose(tempFile);

    printf("Line %d removed from the file.\n", lineNumber);
}

int main() {
    // Example usage
    removeLineWithTempFile("example.txt", 2);

    return 0;
}
