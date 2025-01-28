
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int min_num_coins(vector<ll> &denominations, int n, vector<int> &dp, ll sum)
{

    if (dp[sum] != -1)
    {
        return dp[sum];
    }

    int min_coins = INT32_MAX;

    for (int i = 0; i < n; i++)
    {
        if (sum - denominations[i] >= 0)
        {
            int coins = min_num_coins(denominations, n, dp, sum - denominations[i]);
            if (coins != INT32_MAX)
            {
                min_coins = min(min_coins, 1 + coins);
            }
        }
    }

    dp[sum] = min_coins;
    return dp[sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;
    vector<ll> denominations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> denominations[i];
    }
    vector<int> dp(x + 1, -1);
    dp[0] = 0;

    int result = min_num_coins(denominations, n, dp, x);

    if (result == INT32_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}
