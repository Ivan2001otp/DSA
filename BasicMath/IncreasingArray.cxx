#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;

    vector<ll> v(N);

    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    ll c = 0;
    for (ll i = 1; i < N; i++)
    {
        ll left = v[i - 1];
        ll right = v[i];

        if (left > right)
        {
            ll rem = left - right;
            c += rem;
            v[i] += rem;
        }
    }

    cout << c << endl;
    return 0;
}