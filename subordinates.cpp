#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(vector<vector<int>> &adj_list, int node, vector<int> &ans)
{
    if (adj_list[node].size() == 0)
    {
        return 0;
    }
    for (size_t i = 0; i < adj_list[node].size(); i++)
    {
        ans[node] += (1 + dfs(adj_list, adj_list[node][i], ans));
    }
    return ans[node];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n + 1);
    vector<int> ans(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int val;
        cin >> val;
        adj_list[val].push_back(i);
    }

    dfs(adj_list, 1, ans);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}