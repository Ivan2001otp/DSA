#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N;
    cin >> N;

    ll a = (((N) * (N - 1)) / 2);
    ll b = ((N - 2) * (N - 1)) / 2;
    ll c = (4 * N) + 1;

    
    cout << a + b + c << endl;
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
