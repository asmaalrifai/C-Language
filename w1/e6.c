#include <stdio.h>
int GLOBE_I =20;

f1(){
    GLOBE_I = 10;
}

f2(){
    GLOBE_I = 5;
}

int main(void){
    int GLOBE_I = 30;
//f1();
//f2();
printf("%d\n", GLOBE_I);
{
    extern int GLOBE_i;
    printf("%d", GLOBE_I);
}
}