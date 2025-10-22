#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, K;
    cin >> N >> K;
    ll ans = 0;

    if (K >= N)
    {
        ans = ceil((K * 1.0) / N);
    }
    else
    {
        int newK = ceil((N * 1.0) / K) * K;
        ans = ceil((newK * 1.0) / N);
    }
    cout << ans << endl;
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