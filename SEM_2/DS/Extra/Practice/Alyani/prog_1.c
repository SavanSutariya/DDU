#include <stdio.h>

// Time Complexity: O(N2)
// Auxiliary Space: O(1) 
void insertion(int a[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

// Time Complexity: O(N2)
// Auxiliary Space: O(1) 
void bubble(int a[], int n)
{
    int b;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }
}

int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < pivot)
        {

            i++;

            int b = a[i];
            a[i] = a[j];
            a[j] = b;
        }
    }

    int b = a[i + 1];
    a[i + 1] = a[h];
    a[h] = b;

    return (i + 1);
}

// Time : O(n*log n)
// Space: O(n)
void quick(int a[], int l, int h)
{
    if (l < h)
    {
        int i = partition(a, l, h);
        quick(a, l, i - 1);
        quick(a, i + 1, h);
    }
}

void merge(int left[], int left_length, int right[], int right_length, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < left_length && j < right_length)
    {
        if (left[i] <= right[j])
        {
            result[k++] = left[i++];
        }
        else
        {
            result[k++] = right[j++];
        }
    }

    while (i < left_length)
    {
        result[k++] = left[i++];
    }

    while (j < right_length)
    {
        result[k++] = right[j++];
    }
}

// Time : O(n*log n)
// Space: O(n)
void merge_sort(int a[], int n)
{
    if (n < 2)
    {
        return;
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++){
        left[i] = a[i];
    }

    for (int i = mid; i < n; i++){
        right[i - mid] = a[i];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge(left, mid, right, n - mid, a);
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
}
int main()
{
    int a[]={77,12,22,2,5,25,79,11};
    int n=sizeof(a)/sizeof(a[0]);

    printf("\n-----Bubble Sort-----\n");
    bubble(a, n);
    display(a, n);

    printf("\n-----Quick Sort-----\n");
    quick(a, 0, n - 1);
    display(a, n);

    printf("\n-----Insertion Sort-----\n");
    insertion(a, n);
    display(a, n);

    printf("\n------Merge Sort------\n");
    merge_sort(a,n);
    display(a, n);

    return 0;
}