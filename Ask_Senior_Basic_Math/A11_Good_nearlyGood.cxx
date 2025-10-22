#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b;
    cin >> a >> b;

    if (b == 1)
    {
        cout << "NO" << endl;
        return;
    }
    ll x = a;
    ll z = 2 * a * b;
    ll y = (2 * b - 1) * a;

    cout << "YES" << endl;
    cout << x << " " << y << " " << z << endl;
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