#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    ll half_end = (n / 2);
    ll end = n;
    if (n == 1)
    {
        cout << 1;
    }

    else if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (n == 4)
    {
        cout << "2 4 1 3";
    }

    else
    {
        while (end > (n / 2))
        {
            if (half_end != 0)
            {
                if (half_end == 1 && n % 2 == 0)
                {
                    cout << end << " " << half_end;
                }
                else
                {
                    cout << end << " " << half_end << " ";
                }
            }
            else
            {
                cout << end;
            }
            half_end--;
            end--;
        }
    }
    return 0;
}