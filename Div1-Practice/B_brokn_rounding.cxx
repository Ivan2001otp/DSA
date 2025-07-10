#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll X, K;
    cin >> X >> K;

    ll pow10 = 1;

    for (ll i = 0; i < K; i++)
    {
        X = X / pow10;
        ll last = X % 10;

        if (last <= 4)
        {
            X -= last;
        }
        else
        {
            X += (10 - last);
        }

        X *= pow10;
        pow10 *= 10;
    }

    cout << X << endl;
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