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

    ll N, K;
    cin >> N >> K;

    vector<ll> prime = sieve(1001);
    ll cnt = 0;

    vector<ll> valid;

    for (ll i = 1; i < prime.size(); i++)
    {
        ll num = prime[i] + prime[i - 1] + 1;
        if (isPrime(num))
        {
            valid.push_back(num);
        }
    }

    for (ll i = 0; i < valid.size(); i++)
    {
        if (valid[i] <= N)
        {
            cnt++;
        }
    }

    if (cnt >= K)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}