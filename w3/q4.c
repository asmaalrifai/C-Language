#include <stdio.h>

int main(){
    int a = 5;
    int b =8;
    int *ptr1 = &a;
    int *ptr2 = &b;
    printf("a is : %d \nb is : %d \n", *ptr1, *ptr2);

    /*int *ptr3 = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = *ptr3; */

    int temp = a;
    a = b;
    b = temp;   
    printf("a is : %d \n b is : %d \n", *ptr1, *ptr2);
}