#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct to hold range information
struct ranges {
    int l, r, in;
    // Overloads the < operator for sorting
    bool operator<(const ranges &other) const {
        if (l == other.l)
            return r > other.r;
        return l < other.l;
    }
};

vector<vector<int>> checkrange(vector<vector<int>> &r, int n) {
    vector<ranges> range(n);
    vector<int> contains(n, 0), contained(n, 0);

    for (int i = 0; i < n; i++) {
        range[i].l = r[i][0];
        range[i].r = r[i][1];
        range[i].in = i;
    }
    sort(range.begin(), range.end());

    // Check if a range contains another
    int minEnd = INT32_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (range[i].r >= minEnd)
            contains[range[i].in] = 1;

        minEnd = min(minEnd, range[i].r);
    }

    // Check if a range is contained by another
    int maxEnd = 0;
    for (int i = 0; i < n; i++) {
        if (range[i].r <= maxEnd)
            contained[range[i].in] = 1;

        maxEnd = max(maxEnd, range[i].r);
    }

    return {contains, contained};
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> r[i][0] >> r[i][1];
    }

    vector<vector<int>> res = checkrange(r, n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
