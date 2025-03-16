#include <stdio.h>

int sum (int a, int b){
    return a + b;
}

void* returns_func_ptr(){
    return sum;
}

int main(){
    int (*sum_ptr)(int,int)=returns_func_ptr();

    printf("%d",sum_ptr(2,3));
}