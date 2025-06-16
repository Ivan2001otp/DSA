#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int N;
    cin >> N;
    if (N & 1)
    {
        cout << -1 << endl;
        return;
    }

    // 2y = N
    int y = N / 2;
    cout << 1 << " " << y << endl;
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