#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/contest/2173/problem/C
void solve3()
{
}
// https://codeforces.com/contest/2173
void solve1()
{
    ll n, k;
    cin >> n >> k;

    string bs;
    cin >> bs;

    vector<ll> awake(n, 0);

    ll count = 0;

    ll last_one_cover = -1;

    for (ll i = 0; i < n; i++)
    {
        if (bs[i] == '1')
        {
            if (i > last_one_cover)
            {
                ll end = min(n - 1, i + k);
                for (ll j = i; j <= end; j++)
                {
                    awake[j] = 1;
                }
                last_one_cover = end;
            }
        }
    }

    for (ll i = 0; i < awake.size(); i++)
    {
        if (!awake[i])
            ++count;
    }

    cout << count << endl;
    return;
}

void solve2()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll R = 0, L = 0;

    for (int i = 0; i < n; i++)
    {
        ll l_a = L - a[i];
        ll r_a = R - a[i];

        ll b_r = b[i] - R;
        ll b_l = b[i] - L;

        L = min(l_a, b_r);
        R = max(r_a, b_l);
    }

    cout << "ans is " << max(L, R) << endl;
}

signed int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}