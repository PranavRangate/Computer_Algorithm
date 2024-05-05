#include <iostream>
using namespace std;

int knapsack(int n, int profit[], int weight[], int cap)
{
    if (n == 0 || cap == 0)
    {
        return 0;
    }
    if (weight[n - 1] <= cap)
    {
    	
        return max(profit[n - 1] + knapsack(n
		 - 1, profit, weight, cap - weight[n - 1]), knapsack(n - 1, profit, weight, cap));
    }
    else
    {
        return knapsack(n - 1, profit, weight, cap);
    }
}

int main()
{
    int n;
    cin >> n;
    int profit[n];
    int weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    int cap;
    cin >> cap;
    cout << "Profit : " << knapsack(n, profit, weight, cap) << endl;
    return 0;
}
