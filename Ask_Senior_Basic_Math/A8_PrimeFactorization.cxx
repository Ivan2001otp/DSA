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
        ll X, Y;
        cin >> X >> Y;

        if (abs(X - Y) > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}