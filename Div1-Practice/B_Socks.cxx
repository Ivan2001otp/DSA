#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N;
    cin >> N;
    vector<ll> v(N);

    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    unordered_map<ll, ll> mp;

    for (auto a : v)
    {
        mp[a]++;
    }

    int cnt = 0;
    for (auto a : mp)
    {
        cnt += a.second / 2;
    }

    cout << cnt << endl;
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