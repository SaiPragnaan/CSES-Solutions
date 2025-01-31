#include <bits/stdc++.h>
using namespace std;
#define ll long long

int naive(string str, string sub_str)
{
    size_t pos = str.find(sub_str);
    int position = 0;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int j = 0, k = i;
        while (k < str.length() && j < sub_str.length() && str[k] == sub_str[j])
        {
            j++;
            k++;
        }
        if (j == sub_str.length())
        {
            cnt++;
        }
    }
    return cnt;
}

vector<int> computePrefix(string S)
{
    int N = S.length();
    vector<int> pie(N);
    for (int i = 1; i < N; i++)
    {
        int j = pie[i - 1];
        while (j > 0 && S[j] != S[i])
        {
            j = pie[j - 1];
        }
        if (S[i] == S[j])
        {
            j++;
        }
        pie[i] = j;
    }
    return pie;
}
int optimal(string str, string sub_str)
{
    string combined = sub_str + "#" + str;
    vector<int> pie = computePrefix(combined);
    int cnt = 0;
    for (int i = 0; i < pie.size(); i++)
    {
        if (pie[i] == sub_str.length())
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str, sub_str;
    cin >> str >> sub_str;
    int cnt = optimal(str, sub_str);
    cout << cnt << endl;
    return 0;
}