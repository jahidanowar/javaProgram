#include <stdio.h>
#include <stdlib.h>

/* Swap */
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
/* Quick Sort */
void quicksort(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    int left = low;
    int right = high;

    do
    {

        while (arr[mid] > arr[left])
        {
            left++;
        }
        while (arr[mid] < arr[right])
        {
            right--;
        }

        if (left <= right)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }

    } while (left < right);

    if (low < right)
    {
        quicksort(arr, low, right);
    }
    if (low < high)
    {
        quicksort(arr, left, high);
    }
}

int main()
{

    int arr[7] = {23, 99, 122, 90, 7, 5, 91};

    quicksort(arr, 0, 6);

    for (int i = 0; i <= 6; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
