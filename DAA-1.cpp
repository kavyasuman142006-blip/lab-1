// Name: Kavya suman
//Roll No.: 24/DA/034

#include <iostream>
using namespace std;

//recursive merge sort

// void merge(int arr[], int low, int mid, int high)
// {
//     int i = low;
//     int j = mid + 1;
//     int k = 0;

//     int temp[100];

//     while (i <= mid && j <= high)
//     {
//         if (arr[i] <= arr[j])
//             temp[k++] = arr[i++];
//         else
//             temp[k++] = arr[j++];
//     }

//     while (i <= mid)
//         temp[k++] = arr[i++];

//     while (j <= high)
//         temp[k++] = arr[j++];

//     for (i = low, k = 0; i <= high; i++, k++)
//         arr[i] = temp[k];
// }

// void mergeSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int mid = (low + high) / 2;

//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid + 1, high);

//         merge(arr, low, mid, high);
//     }
// }

// int main()
// {
//     int n;
//     int arr[100];

//     cout << "Enter number of elements: ";
//     cin >> n;

//     cout << "Enter elements: ";
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     mergeSort(arr, 0, n - 1);

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }


//itrative way

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void mergeSortIterative(int arr[], int n)
{
    // size represents the size of subarrays being merged
    for (int size = 1; size < n; size *= 2)
    {
        for (int low = 0; low < n - 1; low += 2 * size)
        {
            int mid = low + size - 1;
            int high = low + 2 * size - 1;

            if (mid >= n - 1)
                continue;

            if (high >= n)
                high = n - 1;

            merge(arr, low, mid, high);
        }
    }
}

int main()
{
    int n;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSortIterative(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}