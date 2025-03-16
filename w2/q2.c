#include <stdio.h>

void printIntArray(int arr[])
{
    int i = 0;

    while (arr[i] != -1)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void printArray(int arr[])
{
    printf("%d\n ", sizeof(arr));
    //int i = 0;
    for (int i = 0; i < sizeof(arr); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, -1};
    printIntArray(arr);

    int arr2[] = {10, 20, 30, -1, 9, 8};
    printArray(arr2);

    return 0;
}
