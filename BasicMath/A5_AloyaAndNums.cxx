#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> sieve(int num)
{

    vector<bool> vis(num, true);
    vector<ll> v;

    for (int i = 2; i * i <= num; i++)
    {
        if (vis[i])
        {
            for (int j = i * i; j <= num; j += i)
            {
                vis[j] = false;
            }
        }
    }

    for (int i = 2; i <= num; i++)
    {
        if (vis[i])
        {
            v.push_back(i);
        }
    }
    return v;
}

bool isPrime(ll num)
{
    // sqrnt(n)
    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, M;
    cin >> N >> M;
    unordered_map<ll, ll> mp1;
    unordered_map<ll, ll> mp2;

    for (ll i = 1; i <= N; i++)
    {
        mp1[i % 5]++;
    }

    for (ll i = 1; i <= M; i++)
    {
        mp2[i % 5]++;
    }

    ll ans = 0;

    for (auto a : mp1)
    {

        if (a.first == 0)
        {
            if (mp2[0])
            {
                ans += mp2[0] * mp1[0];
            }
        }
        else
        {
            ll rem = 5 - a.first;
            if (mp2[rem])
            {
                ans += (a.second * mp2[rem]);
            }
        }
    }

    cout << ans << " ";
    return 0;
}