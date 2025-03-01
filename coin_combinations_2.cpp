#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll modulo = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int denom;

    vector<ll> dp(x + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> denom;
        for (int sum = 0; sum <= x - denom; sum++)
        {
            dp[sum + denom] = (dp[sum + denom] + dp[sum]) % modulo;
        }
    }
    cout << dp[x] << endl;
    return 0;
}