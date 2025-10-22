#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N;
    cin >> N;

    vector<ll> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](const ll &a, const ll &b)
         { return a % 2 < b % 2; });

    ll c = 0;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = i + 1; j < N; j++)
        {
            c += (__gcd(v[i], 2 * v[j]) > 1);
        }
    }

    cout << c << endl;
    return;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
