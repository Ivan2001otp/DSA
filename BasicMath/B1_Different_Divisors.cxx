#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> sieve(ll N)
{
    vector<ll> pm;
    vector<bool> prime(N, true);

    for (ll p = 2; p * p <= N; p++)
    {
        if (prime[p])
        {
            for (ll j = p * p; j <= N; j += p)
            {
                prime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= N; i++)
    {
        if (prime[i])
            pm.push_back(i);
    }

    return pm;
}

void solve(vector<ll> &prime)
{
    ll D = 170;

    cin >> D;
    ll target1 = D + 1;

    ll index1 = lower_bound(prime.begin(), prime.end(), target1) - prime.begin();

    ll a1 = prime[index1];

    ll target2 = a1 + D;
    ll index2 = lower_bound(prime.begin(), prime.end(), target2) - prime.begin();

    ll a2 = prime[index2];

    cout << a1 * a2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    vector<ll> prime = sieve(100000);
    while (t--)
    {
        solve(prime);
    }
    return 0;
}