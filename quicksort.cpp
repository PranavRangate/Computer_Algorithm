#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot=arr[start];
    int count=0;

    for (int i = start + 1; i <= end; i++)
    {
       if (arr[i]<=pivot)
       {
         count++;
       }
       
    }
    // pivot index is at right position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start;
    int j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotIndex)
        {
            i++;
        }
        while (arr[j] > pivotIndex)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quicksort(int arr[], int start, int end)
{
    // base codition of recursion
    if (start > end)
    {
        return;
    }
    int p = partition(arr, start, end);
    // sort left part
    quicksort(arr, start, p-1);
    // sort right part
    quicksort(arr, p + 1, end);
}
int main()
{
    int n;
    cout << "enter the no elements of array :" << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);
    cout << "the sorted array elements are :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}