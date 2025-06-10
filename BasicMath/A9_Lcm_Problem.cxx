#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;

    while (T--)
    {
        ll l, r;
        cin >> l >> r;

        int new_r = 2 * l;
        if (l <= new_r && new_r <= r)
        {
            cout << l << " " << new_r << endl;
        }
        else
        {
            cout << -1 << " " << -1 << endl;
        }
    }

    return 0;
}