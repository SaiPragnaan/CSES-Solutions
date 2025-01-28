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

    vector<int> values(n);
    vector<int> indices(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < n; i++)
    {
        indices[values[i]] = i;
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (indices[i] < indices[i - 1])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}