#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9 + 7;

ll power2(ll n)
{
    ll res = 1;
    ll x = 2;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (1LL * res * (x % modulo)) % modulo;
        }
        x = (1LL * (x % modulo) * (x % modulo)) % modulo;
        n >>= 1;
    }
    return res % modulo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    cout << power2(n);
    return 0;
}