#include <stdio.h>

void printArray ( int number[]){
int length = sizeof(number)/sizeof(number[1]);
    for (size_t i = 0; i<length; i++){
        printf("%d" , number[1] );
    }
}

int main(){
    int num[] = {1,5,8,4,7,3,6};
    printArray(num);
    return 0;
}