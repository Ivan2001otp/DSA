#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int a, b;
    cin >> a >> b;
    int ans = 1;

    for (int i = b; i >= max({a + 1, b - 5, 1}); i--)
    {
        ans = (ans * i) % 10;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}