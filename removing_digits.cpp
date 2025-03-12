#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX-10);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int d = i;
        while (d > 0)
        {
            dp[i] = min(dp[i], dp[i - (d % 10)] + 1);
            d /= 10;
        }
    }
    cout << dp[n] << endl;
    // int a=a;
    return 0;
}

