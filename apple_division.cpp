#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int idx, int n, ll sum1, ll sum2, vector<ll> vec)
{
    if (idx == n)
    {
        return abs(sum1 - sum2);
    }
    ll choose = solve(idx + 1, n, sum1 + vec[idx], sum2, vec);
    ll not_choose = solve(idx + 1, n, sum1, sum2 + vec[idx], vec);

    return min(choose, not_choose);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    cout <<solve(0, n, 0, 0, vec);
    return 0;
}