#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<string> &map, vector<vector<bool>> &visited, int i, int j) // Pass map by reference
{
    visited[i][j] = true;
    int n = map.size(), m = map[0].size();

    if (i > 0 && map[i - 1][j] == '.' && !visited[i - 1][j])
        dfs(map, visited, i - 1, j);
    if (i < n - 1 && map[i + 1][j] == '.' && !visited[i + 1][j])
        dfs(map, visited, i + 1, j);
    if (j > 0 && map[i][j - 1] == '.' && !visited[i][j - 1])
        dfs(map, visited, i, j - 1);
    if (j < m - 1 && map[i][j + 1] == '.' && !visited[i][j + 1])
        dfs(map, visited, i, j + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    
    for (int i = 0; i < n; i++)
        cin >> map[i];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '.' && !visited[i][j])
            {
                cnt++;
                dfs(map, visited, i, j);
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}
