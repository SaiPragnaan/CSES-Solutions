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
    vector<int> vec(n);
    ll X = 1LL;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end());
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > X)
        {
            break;
        }
        X += vec[i];
    }
    cout << X << endl;
    return 0;
}