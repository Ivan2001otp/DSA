#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

multiset<ll> printFactorization(ll n)
{
    multiset<ll> pf;

    while (n % 2 == 0)
    {
        n = n / 2;
        pf.insert(2);
    }

    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {   
            n = n/i;
            pf.insert(i);
        }
    }

    if (n > 2)
        pf.insert(n);

    return pf;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, K;
    cin >> N >> K;
    multiset<ll> mt = printFactorization(N);
    if (mt.size() < K)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        while (mt.size() > K)
        {
            ll first = *mt.begin();
            ll last = *mt.rbegin();
            mt.erase(mt.begin());
            mt.erase(--mt.end());

            mt.insert(first * last);
        }
    }

    // cout << mt.size() << endl;
    for (auto a : mt)
    {
        cout << a << " ";
    }

    return 0;
}