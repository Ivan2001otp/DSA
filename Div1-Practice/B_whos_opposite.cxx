#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int N = abs(a - b) * 2;
    if (a > N || b > N || c > N)
    {
        cout << -1 << endl;
        return;
    }

    int d = c + N / 2;

    while (d > N)
        d = d - N;
    cout << d << endl;
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