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
    ll curr = -1;
    ll moves = 0;
    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        if (val < curr)
        {
            moves += curr - val;
        }
        else
        {
            curr = val;
        }
    }
    cout << moves << endl;
    return 0;
}