#include <stdio.h>


void swapPointers(int** ptr1, int** ptr2) {
    int* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a = 5, b = 10;
    int* ptrA = &a;
    int* ptrB = &b;

   
    printf("Before swapping:\n");
    printf("ptrA points to %d\n", *ptrA);
    printf("ptrB points to %d\n", *ptrB);


    swapPointers(&ptrA, &ptrB);

    
    printf("\nAfter swapping:\n");
    printf("ptrA points to %d\n", *ptrA);
    printf("ptrB points to %d\n", *ptrB);

    return 0;
}
