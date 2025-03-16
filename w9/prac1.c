#include <stdio.h>

int main(void) {
    FILE *fh;

    // Open file in append mode ("a") instead of write mode ("w")
    fh = fopen("io.txt", "a");

    // Check if the file is successfully opened
    if (fh == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }

    // Write data to the file
    fputs("abc", fh);
    fputs("123\n", fh);
    fputs("A string\n", fh);

    // Close the file
    fclose(fh);

    return 0;
}
