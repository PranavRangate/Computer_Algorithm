#include <iostream>
using namespace std;
int binarysearch(int arr[], int low, int high, int key)
{
    int mid;
    if (low > high)
    {
        return -1;
    }
    mid = (low + high) / 2;
    if (key == arr[mid])
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        return binarysearch(arr, mid + 1, high, key);
    }
    else
    {
        return binarysearch(arr, low, mid - 1, key);
    }
}
int main()
{
    int n;
    cout << "enter the no of elements" << endl;
    cin >> n;
    int arr[n];
    cout << "enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "enter the key to search" << endl;
    cin >> key;
    int ans = binarysearch(arr, 0, n - 1, key);
    cout << ans << endl;

    return 0;
}