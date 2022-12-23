#include <stdio.h>
#define SIZE 50

void shift_element(int *arr, int i)
{
    for (int j = 0; j < i; j++)
    {
        *(arr + i - j) = *(arr + i - j - 1);
    }
}

void printArr(int *arr, int size)
{
    printf("%d", *arr);
    for (int i = 1; i < size; i++)
    {
        printf(",%d", *(arr + i));
    }
    printf("\n");
}

void insertion_sort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int *ptr = (arr + i - 1);
        int count = 0;
        while (*ptr >= *(arr + i))
        {
            count++;
            ptr--;
            if ((ptr + 1) == arr)
            {
                break;
            }
        }
        ptr++;
        int temp = *(arr + i);
        shift_element(ptr, count);
        *ptr = temp;
    }
}

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf(" %d", (arr + i));
    }
    insertion_sort(arr, SIZE);
    printArr(arr, SIZE);
    return 0;
}