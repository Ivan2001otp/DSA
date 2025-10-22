#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N;
    cin >> N;
    vector<ll> v(N);

    ll sum = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    ll rem = sum % N;
    ll non_affected = N - rem;

    cout << rem * non_affected << endl;
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
