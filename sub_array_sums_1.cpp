#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<ll> que;
    int n;
    ll x;
    cin >> n >> x;
    ll sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        que.push(val);
        sum += val;
        if (sum == x)
            cnt++;
        else if (sum > x)
        {
            while (sum > x)
            {
                sum -= que.front();
                que.pop();
            }
            if (sum == x)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}