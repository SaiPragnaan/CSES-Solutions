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
    vector<int> tower_top;
    for (int i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        if (tower_top.size() == 0)
        {
            tower_top.push_back(k);
            continue;
        }
        auto it = upper_bound(tower_top.begin(), tower_top.end(), k);
        if (it == tower_top.end())
        {
            tower_top.push_back(k);
        }
        else
        {
            *it = k;
        }
    }
    cout << tower_top.size() << endl;
    return 0;
}