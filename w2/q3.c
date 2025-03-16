#include <stdio.h>
#include <stdbool.h>

void countTrue(bool value) {
    static int trueCount = 0;
    if (value) {
        trueCount++;
    }
    printf("Function called with true %d times.\n", trueCount);
}

int main() {
    
    countTrue(true);
    countTrue(false);
    countTrue(true);
    countTrue(true);
    countTrue(false);
    countTrue(true);

    return 0;
}
