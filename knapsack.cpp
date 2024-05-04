#include <iostream>
using namespace std;

void sort(float ratio[], float n)
{
    float temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
            }
        }
    }
}

float knapsack(float profit[], float weight[], int n, int m)
{
    float profit1 = 0;
    float ratio[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (profit[i]/weight[i]);
    }

    sort(ratio, n);
    for (int i = 0; i < n; i++)
    {
        if (m > 0 &&  weight[i] <= m)
        {
            m = m - weight[i];
            profit1 = profit1 + profit[i];
        }
        else if (m > 0)
        {
            profit1 = profit1 + profit[i] * (m / weight[i]);
        }
    }
    return profit1;
}
int main()
{

    int n, m;
    cout << "enter the no of items and size of knapsack :" << endl;
    cin >> n >> m;

    float profit[n];
    float weight[n];

    cout << "enter the profit:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    cout << "enter the weight:" << endl;
    for (int j = 0; j < n; j++)
    {
        cin >> weight[j];
    }

    float ans = knapsack(profit, weight, n, m);
    cout << ans << endl;
}