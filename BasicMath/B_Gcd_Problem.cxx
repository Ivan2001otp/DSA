#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cx + cy + c = N
    // when c=1, x+y = N-1
    ll t;
    cin >> t;

    while (t--)
    {

        ll N;
        cin >> N;
        ll c = 1;
        ll a, b;

        for (ll i = 1;; i++)
        {
            a = i;
            b = (N / c) - 1 - i;

            if (__gcd(a, b) == c)
            {
                if (a != b && b != c && a != c)
                {
                    cout << a << " " << b << " " << c << endl;
                    break;
                }
            }
        }
    }

    return 0;
}