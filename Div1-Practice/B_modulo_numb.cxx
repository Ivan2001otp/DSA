#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    const int mod = 998244353;
    ll N;
    cin >> N;
    for (ll x = 0; x < 998244353; x++)
    {
        if (((N % mod) - (x % mod)) % (998244353) == 0)
        {
            cout << x << endl;
            break;
        }
    }

    return;
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