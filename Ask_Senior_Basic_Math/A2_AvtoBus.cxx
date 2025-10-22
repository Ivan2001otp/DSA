#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    // 2x + 3y = n/2
    while (t--)
    {
        ll n;
        cin >> n;

        if (n % 2 == 1 || n == 2)
        {
            cout << -1 << endl;
        }
        else
        {
            n = n / 2;

            cout << ((n + 3 - 1) / 3) << " " << (n / 2) << endl;
        }
    }
    return 0;
}