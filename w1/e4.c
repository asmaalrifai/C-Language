#include <stdio.h>

int main(void){
    printf("long %d \n", sizeof(long));
    int i;
    printf("var %d\n", sizeof(i));
    char chars [10];
    printf("char %d \n", sizeof(chars));
    return 0;
}