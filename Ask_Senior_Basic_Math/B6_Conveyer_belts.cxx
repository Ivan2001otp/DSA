#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int N;
    int x1, y1, x2, y2;
    cin >> N;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    int l1 = min({x1, N - x1 + 1, y1, N - y1 + 1});
    int l2 = min({x2, N - x2 + 1, y2, N - y2 + 1});

    cout <<  abs(l1 - l2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}