#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>> &map, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (auto &neighbor : map[node])
    {
        if (!visited[neighbor])
        {
            dfs(map, visited, neighbor);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    int cnt = 0;
    vector<int> cluster_heads;
    vector<bool> visited(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(map, visited, i);
            cnt++;
            cluster_heads.push_back(i);
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 0; i < cluster_heads.size() - 1; i++)
    {
        cout << cluster_heads[i] << " " << cluster_heads[i + 1] << endl;
    }

    return 0;
}