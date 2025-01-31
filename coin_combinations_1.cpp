#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll modulo = 1e9 + 7;

ll solve(int sum, vector<int> denom, vector<ll> &dp)
{
    int n = denom.size();
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= denom[j])
            {
                dp[i] = (dp[i] + dp[i - denom[j]]) % modulo;
            }
        }
    }
    return dp[sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> denominations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> denominations[i];
    }
    vector<ll> dp(x + 1);
    dp[0] = 1;
    cout << solve(x, denominations, dp) << endl;
    return 0;
}