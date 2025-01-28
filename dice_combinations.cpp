#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll modulo = 1e9 + 7;
vector<int> dp(1e6 + 5, -1);

ll solve(int sum)
{
    if (dp[sum] != -1)
    {
        return dp[sum]%modulo;
    }
    if (sum <= 6)
    {
        for (ll i = 1; i <= sum; i++)
        {
            dp[sum] = (dp[sum]+solve(sum - i) % modulo)%modulo;
        }
        dp[sum] += 1;
    }
    else
    {
        for (ll i = 1; i <= 6; i++)
        {
            dp[sum] = (dp[sum]+solve(sum - i) % modulo)%modulo;
        }
    }
    dp[sum] += 1 % modulo;

    return dp[sum]%modulo;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    cout << solve(n);
    return 0;
}