/**
 * @file Sort.cpp
 * @author Jahid A M(jahidanowar.mustafa@mscsa.christuniversity.in)
 * @registeration: 2147033
 * @brief This file contains the implementation of the Sort funtions.
 * @date 2022-02-04
 *
 */

#include <iostream>
using namespace std;

// Insertion Sort Function
void insertionSort(int arr[], int left, int right)
{
    // Initialize variables
    int i, key, j;
    // Loop through array
    for (i = left + 1; i <= right; i++)
    {
        // Set key to current element
        key = arr[i];
        // Set j to i - 1
        j = i - 1;
        // Loop through array
        while (j >= left && arr[j] > key)
        {
            // Shift elements
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Add key to array
        arr[j + 1] = key;
    }
}

// Selection Sort Function
void selectionSort(int arr[], int left, int right)
{
    // Initialize variables
    int i, j, min_idx;
    // Loop through array
    for (i = left; i < right; i++)
    {
        // Set min_idx to i
        min_idx = i;
        // Loop through array
        for (j = i + 1; j <= right; j++)
        {
            // Check if element is smaller than min_idx
            if (arr[j] < arr[min_idx])
            {
                // Set min_idx to j
                min_idx = j;
            }
        }
        // Swap elements
        swap(arr[i], arr[min_idx]);
    }
}

// Merge Sort Function
void mergeSort(int arr[], int left, int right)
{
    // Check if left is less than right
    if (left < right)
    {
        // Initialize variables
        int mid = left + (right - left) / 2;
        // Sort left half
        mergeSort(arr, left, mid);
        // Sort right half
        mergeSort(arr, mid + 1, right);
        // Merge halves
        merge(arr, left, mid, right);
    }
}

// Merge Function
void merge(int arr[], int left, int mid, int right)
{
    // Initialize variables
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    // Copy left half to L
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    // Copy right half to R
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    // Merge L and R
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        // Check if L[i] is smaller than R[j]
        if (L[i] <= R[j])
        {
            // Add L[i] to array
            arr[k] = L[i];
            // Increment i
            i++;
        }
        else
        {
            // Add R[j] to array
            arr[k] = R[j];
            // Increment j
            j++;
        }
        // Increment k
        k++;
    }
    // Add remaining elements of L to array
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Add remaining elements of R to array
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Utility Function
int countArrayEl(int arr[])
{
    return sizeof(arr) / sizeof(arr[0]);
}

void printArray(int arr[])
{
    // Loop through array
    for (int i = 0; i < countArrayEl(arr); i++)
    {
        // Print element
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Main
int main()
{
    // Initialize variables
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = countArrayEl(arr);
    // Print array
    cout << "Given array is \n";
    printArray(arr);
    cout << "\n";
    // Sort array
    insertionSort(arr, 0, n - 1);
    // Print sorted array
    cout << "After insertion sort, array is \n";
    printArray(arr);
    cout << "\n";

    mergeSort(arr, 0, n - 1);
    // Print sorted array
    cout << "After merge sort, array is \n";
    printArray(arr);
    cout << "\n";

    selectionSort(arr, 0, n - 1);
    // Print sorted array
    cout << "After selection sort, array is \n";
    printArray(arr);
    cout << "\n";

    return 0;
}