#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    ll p = 1;
    vector<ll> v;
    for (int i = 0; i < s.size(); i++)
    {
        v.push_back(s[i] - '0');
    }

    ll ans = INT_MIN;
    int n = v.size();

    ans = max(1LL, v[0] - 1) * pow(9, n - 1);

    for (int i = 0; i < n; i++)
    {
        p = p * v[i];
    }

    ans = max(ans, p); // 49999, 58347

    p = 1;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, p * (v[i] - 1) * ((long long)pow(9, n - i - 1)));
        p = p * v[i];
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