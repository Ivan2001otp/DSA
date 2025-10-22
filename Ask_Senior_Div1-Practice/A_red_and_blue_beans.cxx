#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll r, b, d;
    cin >> r >> b >> d;

    if (r > b)
    {
        swap(r, b);
    }
    if (b > (r * (d + 1)))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
