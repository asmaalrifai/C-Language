#include <stdio.h>

int main() {
    int size_int_float = sizeof(int) + sizeof(float);
    int size_float_double = sizeof(float) + sizeof(double);
    int result =

    printf("Size of int + float pair: %d bytes\n", size_int_float);
    printf("Size of float + double pair: %d bytes\n", size_float_double);

    return 0;
}
