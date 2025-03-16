#include <stdio.h>

int main(){
     void *genptr = malloc(sizeof(int));
     
     int a=5;
    genptr = (int *)a;
    printf("%d", genptr);
}