/**
 * @file BinarySearch.c
 * @author Jahid A M (2147033)
 * @date 2022-03-03
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Binary Search Algorithm
 * Search elements in an array, if found then return the index otherwise returns -1
 * @param arr
 * @param key
 * @param first
 * @param last
 * @return int
 */
int binarySearch(int arr[], int key, int first, int last)
{
    // If the last index is bigger than first
    if (last >= first)
    {
        int mid;
        // Calculating the mid point
        mid = first + (last - first) / 2;
        // If the mid index element is equal to search key then it's the result
        if (arr[mid] == key)
        {
            return mid;
        }
        // If the mid index element is bigger than the key then the key should be present in left side of mid
        if (arr[mid] > key)
        {
            // Applying the BS on left side
            return binarySearch(arr, key, first, mid - 1);
        }
        // Applying BS on right side
        return binarySearch(arr, key, mid + 1, last);
    }

    // if the value of first and last is same or fist is bigger then returns -1 to indicate that the element is not there in the array
    return -1;
}

int main()
{
    int array[] = {3, 4, 5, 6, 7, 8, 9, 11, 17, 34, 99, 100};
    int n = sizeof(array) / sizeof(array[0]);
    int key = 11;

    int result = binarySearch(array, key, 0, n - 1);
    if (result == -1)
        printf("Not found");
    else
        printf("Element is found at index %d", result);

    return 0;
}