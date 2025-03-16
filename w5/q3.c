#include <stdio.h>

int sum(int a, int b){
    return a+b;
}

float avg(int a , int b){
    return (a+b)/2;
}

void* return_func_ptr(int a){// just a condition
    void* res;
    if(a<5){
        res=  sum;
    }
    else{
        res= avg;
    }
    return res;
}

int main(){
    int (*test)(int, int) = return_func_ptr(7);

    printf("%d", test(5,9));
}