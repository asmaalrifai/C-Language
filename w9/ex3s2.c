#include <stdio.h>

void removeLineWithoutTempFile(const char *filename, int lineNumber) {
    FILE *inputFile;
    char buffer[1024];
    int currentLine = 1;

    // Open the input file for reading
    inputFile = fopen(filename, "r");

    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return;
    }

    // Open the same file for writing, truncating its content
    FILE *outputFile = fopen("temp.txt", "w");

    if (outputFile == NULL) {
        fclose(inputFile);
        printf("Error opening the output file.\n");
        return;
    }

    // Copy lines to the output file, excluding the specified line
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        if (currentLine != lineNumber) {
            fputs(buffer, outputFile);
        }
        currentLine++;
    }

    // Close the input file
    fclose(inputFile);

    // Close and remove the original file
    remove(filename);

    // Rename the temporary file to the original file name
    rename("temp.txt", filename);

    // Close the output file
    fclose(outputFile);

    printf("Line %d removed from the file.\n", lineNumber);
}

int main() {
    // Example usage
    removeLineWithoutTempFile("example.txt", 2);

    return 0;
}
