#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    ll cnt = 0;
    while (n != 0)
    {
        cnt += (n / 5);
        n /= 5;
    }

    cout << cnt << endl;
    return 0;
}