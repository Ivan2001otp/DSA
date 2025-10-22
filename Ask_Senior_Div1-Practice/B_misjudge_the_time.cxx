#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int h, int m)
{
    int h1 = h / 10;
    int h2 = h % 10;

    int m1 = m / 10;
    int m2 = m % 10;

    ll newH = h1 * 10 + m1;
    ll newM = h2 * 10 + m2;

    return (0 <= newH && newH < 24) && (0 <= newM && newM < 60);
}

void solve()
{
    int H, M;
    cin >> H >> M;
    while (!check(H, M))
    {
        M++;
        if (M == 60)
        {
            M = 0;

            H++;
            if (H == 24)
            {
                H = 0;
            }
        }
    }
    cout << H << " " << M << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}