#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll A = a * d;
    ll B = c * b;
    if (A == B)
        cout << "0" << endl;
    else if (A == 0 || B == 0)
        cout << "1" << endl;
    else if ((A % B == 0) || (B % A == 0))
        cout << "1" << endl;
    else
    {
        cout << "2" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}