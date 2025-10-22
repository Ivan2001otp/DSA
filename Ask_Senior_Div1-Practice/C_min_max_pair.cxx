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
        v[i]--;
    }

    ll cnt = 0;

    ll consider = 0;
    for (ll i = 0; i < N; i++)
    {
        if (i == v[i])
        {
            ++consider;
        }
    }

    cnt += (consider * (consider - 1)) / 2;

    // different case
    for (ll i = 0; i < N; i++)
    {

        if (v[v[i]] == i && v[i] > i)
        {
            ++cnt;
        }
    }

    cout << cnt << endl;
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