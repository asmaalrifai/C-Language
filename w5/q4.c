#include <stdio.h>
// dont change the code just add a new one
int avg(int a, int b)
{
    return (a + b) / 2;
}
int sum(int a, int b)
{
    return (a + b);
}
int sub(int a, int b)
{
    return (a - b);
}

int main()
{
    // diont call the funcs but write the names
    // midterm questions +synatx clue
    int (*ptr[3])(int, int) = {avg, sum, sub}; // func pointer array
    int min = ptr[0](3,5);
    int (*min_fun)(int,int);

    for (size_t i = 0; i < 3; i++)
    {
        if (min > ptr[i](3, 5))
        {
            min = ptr[i](3, 5);
            min_fun =ptr[1];
            //something here
        }
    }
    printf("%p", min_fun);//%p adress in hexadecimel
    printf("%d", min);
}