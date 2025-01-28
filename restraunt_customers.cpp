#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<vector<int>> customers, int n)
{
    vector<int> arr(n);
    vector<int> dep(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = customers[i][0];
        dep[i] = customers[i][1];
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0, j = 0;
    int cur_customers = 0, max_customers = 0;
    while (i < n && j < n)
    {
        if (arr[i] < dep[j])
        {
            cur_customers++;
            max_customers = max(max_customers, cur_customers);
            i++;
        }
        else
        {
            cur_customers--;
            j++;
        }
    }
    return max_customers;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<int>> times(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> times[i][0] >> times[i][1];
    }
    cout << solve(times, n);
    return 0;
}