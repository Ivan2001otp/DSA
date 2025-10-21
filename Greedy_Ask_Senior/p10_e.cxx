#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1791/E
void f()
{
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll sum = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            v[i] = -1 * v[i];
            cnt++;
        }

        sum += v[i];
    }

    if (cnt % 2 == 0)
    {
        cout << sum << endl;
        return;
    }
    else
    {
        sort(v.begin(), v.end());

        // very important concept by observation- difference
        cout << sum - (2 * v[0]) << endl;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}