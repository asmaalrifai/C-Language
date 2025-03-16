#include <stdio.h>

int fun(int a, int b){
return a+b;
}

int main(){
int (*f)(int, int)= fun;

printf("The sum of %d and %d = %d", 5,2,f(5,2));


}