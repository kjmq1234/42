#include <stdio.h>
#include <stdlib.h>

void partition(int* arr, int low, int high, int *pivot);
void ft_qsort(int* arr, int low, int high, int pivot);
void swap(int* num1, int* num2);

int main(void)
{
    int num;
    int* arr;

    scanf("%d", &num);
    arr = (int*) malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    ft_qsort(arr, 0, num - 1, 0);
    for (int i = 0; i < num; i++)    
        printf("%d ", arr[i]);
}

void ft_qsort(int* arr, int low, int high, int pivot)
{
    if (low < high)
    {
        for (int i = low; i <= high; i++)    
            printf("%d ", arr[i]);
        printf("\n");  
        partition(arr, low, high, &pivot);
        ft_qsort(arr, low, pivot - 1, pivot);
        ft_qsort(arr, pivot + 1, high, pivot);
    }
}
void partition(int* arr, int low, int high, int *pivot)
{
    int pivot_val = arr[low];
    int j = low;

    for (int i  = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot_val)
        {
            j++;       
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    *pivot = j;
}

void swap(int* num1, int* num2)
{
    int tmp = *num1;

    *num1 = *num2;
    *num2 = tmp;
}