#include <stdio.h>

int add(int a, int b){
    return a+b;
}

int (*getAddFunction())(int,int){
    return add;
}

int main(void){
int (*addFunc)(int,int) = getAddFunction();

int result = addFunc(5,3);

printf("Result: %d\n", result);
}