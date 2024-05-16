#include <iostream>
using namespace std;

int flyod(int arr[][100], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    cout << "all pair shortest path" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl; 
    }
}
int main()
{
    int n;
    cout << "enter the value of n" << endl;
    cin >> n;
    int cost[n][100];
    cout << "enter the cost" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    flyod(cost, n);
    return 0;
}