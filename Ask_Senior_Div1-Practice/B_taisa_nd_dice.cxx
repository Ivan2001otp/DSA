#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N, S, R;
    cin >> N >> S >> R;

    vector<ll> v(N, 0);
    v[N - 1] = S - R;
    int maxi = v[N - 1];

    int a = R / (N - 1);
    int b = R % (N - 1);

    for (int i = 0; i < N - 1; i++)
    {
        if (i == N - 2)
        {
            v[i] = a + b;
        }
        else
        {
            v[i] = a;
        }
    }

    sort(v.begin(), v.end());

    int i = 0;
    while (v[N - 1] > maxi)
    {
        --v[N - 1];
        ++v[i];
        i++;
    }

    for (auto a : v)
    {
        cout << a << " ";
    }

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
