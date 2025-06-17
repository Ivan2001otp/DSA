#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);

    for (ll i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    vector<pair<ll, pair<ll, ll>>> v;

    for (ll i = 0; i < N; i++)
    {
        v.push_back({a[i] + b[i], {a[i], b[i]}});
    }

    sort(v.begin(), v.end(), [](const pair<ll, pair<ll, ll>> &p1, const pair<ll, pair<ll, ll>> &p2)
         { return p1.first > p2.first; });

    ll res = 0;
    bool aliceTurn = true;
    for (auto a : v)
    {

        if (aliceTurn)
        {
            res = res + (a.second.first - 1);
        }
        else
        {
            res += (-a.second.second + 1);
        }
        aliceTurn = !aliceTurn;
    }

    cout << "Res : " << res << endl;
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