#include <stdio.h>
int LinearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int BinarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    printf("\nLinear Search\n");
    int index = LinearSearch(arr, size, key);
    if (index == -1)
        printf("Element not found in the array");
    else
        printf("Element found at index %d", index);
    printf("\nBinary Search\n");
    index = BinarySearch(arr, size, key);
    if (index == -1)
        printf("Element not found in the array");
    else
        printf("Element found at index %d", index);
    return 0;
}
