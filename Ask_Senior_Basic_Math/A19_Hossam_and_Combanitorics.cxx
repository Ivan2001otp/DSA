#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N;
    cin >> N;
    vector<ll> v(N);
    unordered_map<ll, ll> mp;

    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }

    sort(v.begin(), v.end());
    ll diff = v[N - 1] - v[0];

    if (diff == 0)
    {
        cout << N * (N - 1) << endl;
        return;
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        ll pos = v[i] + diff;
        ll neg = v[i] - diff;

        if (mp[pos])
        {
            ans += mp[pos];
        }
        if (mp[neg])
        {
            ans += mp[neg];
        }
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