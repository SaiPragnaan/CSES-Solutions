#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> bfs(vector<vector<int>> &adj_list)
{
    int n = adj_list.size() - 1;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == n)
            break;

        for (auto &neighbor : adj_list[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true; 
                q.push(neighbor);
                parent[neighbor] = node;
            }
        }
    }

    if (!visited[n]) 
        return {};

    vector<int> path;
    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<int> shortest_path = bfs(adj_list);

    if (shortest_path.empty())
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << shortest_path.size() << endl;
        for (int node : shortest_path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
