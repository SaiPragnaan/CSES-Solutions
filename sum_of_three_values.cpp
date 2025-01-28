#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<ll, int>> storage(n);
    for (int i = 0; i < n; i++)
    {
        cin >> storage[i].first;
        storage[i].second = i + 1;
    }
    sort(storage.begin(), storage.end());

    for (int i = 0; i < n; i++)
    {
        int req_sum = x - storage[i].first;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (storage[j].first + storage[k].first == req_sum)
            {
                cout << storage[i].second << " " << storage[j].second << " " << storage[k].second;
                return 0;
            }
            else if (storage[j].first + storage[k].first > req_sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}