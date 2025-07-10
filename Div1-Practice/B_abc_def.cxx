#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    const ll mod = 998244353;
    ll a, b, c, d, e, f;

    cin >> a >> b >> c >> d >> e >> f;

    ll ans = ((((a % mod) * (b % mod) * (c % mod)) % mod) - (((d % mod) * (e % mod) * (f % mod)) % mod)) % mod;

    if (ans < 0)
    {
        ans += mod;
    }

    ans = ans % mod;

    cout << ans << endl;
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