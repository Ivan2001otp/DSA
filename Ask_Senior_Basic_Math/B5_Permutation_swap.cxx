#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    vector<int> v(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i + 1];
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i + 1] == i + 1)
        {
            continue;
        }

        int K = abs(v[i + 1] - (i + 1));
        ans = __gcd(ans, K);
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    // vector<ll> prime = sieve(100000);
    while (t--)
    {
        solve();
    }
    return 0;
}