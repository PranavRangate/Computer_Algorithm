#include <iostream>
using namespace std;

struct job
{
    char id;
    int profit;
    int deadline;
};

void sort(job arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].profit < arr[j + 1].profit)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int jobseq(job arr[], int n, int maxdeadline)
{
    sort(arr, n);
    bool timeslot[maxdeadline] = {0};
    int max_profit = 0;
    for (int i = 0; i < n; i++)
    {
        int d = min(maxdeadline, arr[i].deadline);
        for (int j = d - 1; j >= 0; j--)
        {
            if (timeslot[j] == 0)
            {
                timeslot[j] = 1;
                cout << arr[i].id << " ";
                max_profit = max_profit + arr[i].profit;
                break;
            }
        }
    }
    return max_profit;
}
int main()
{
    int n;
    cout << "enter the no of job" << endl;
    cin >> n;
    int maxdeadline;
    cout << "enter the max deadline" << endl;
    cin >> maxdeadline;
    job arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter the id, profit and deadline " << i + 1 << ":" << endl;
        cin >> arr[i].id >> arr[i].profit >> arr[i].deadline;
    }
    int maxprofit = jobseq(arr, n, maxdeadline);
    cout << "The maximum profit that can be obtained is: " << maxprofit << endl;
}