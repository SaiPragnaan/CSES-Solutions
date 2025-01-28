#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int par, int cur, vector<vector<int>> &adj_list, vector<bool> &used, int &cnt)
{
    for (int child : adj_list[cur])
    {
        if (child != par)
        {
            dfs(cur, child, adj_list, used, cnt);
        }
    }
    if (!used[par] && !used[cur] && par != 0)
    {
        cnt++;
        used[par] = used[cur] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n + 1);
    vector<bool> used(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int cnt = 0;
    dfs(0, 1, adj_list, used, cnt);
    cout << cnt << endl;
    return 0;
}