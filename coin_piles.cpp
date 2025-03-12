#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll a, b;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if ((2 * a - b)>=0 && (2 * b- a) >=0 && (2 * a - b) % 3 == 0 && (2 * b - a) % 3 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}