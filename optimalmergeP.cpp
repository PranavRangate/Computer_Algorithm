#include <bits/stdc++.h>
using namespace std;
int optimalMP(int size, int arr[])
{
    // create min heap
    priority_queue<int, vector<int>, greater<int> > q;
    // add to the min heap
    for (int i = 0; i < size; i++)
    {
        q.push(arr[i]);
    }
     int count = 0;
    while (q.size() > 1)
    {
        int result = 0;
        // make the addition of two smallest values
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        result = a + b;
        count = count + result;

        // push back the result

        q.push(result);
    }
    return count;
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
    int ans = optimalMP(n,arr);
    cout << ans << endl;
}
