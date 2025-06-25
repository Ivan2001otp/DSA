#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N;
    cin >> N;

    if (N == 1)
    {
        cout << 1 << " " << 0 << endl;
        return;
    }
    if (N == 2)
    {
        cout << 0 << " " << 1 << endl;
        return;
    }

    if (N % 3 == 0)
    {
        cout << N / 3 << " " << N / 3 << endl;
        return;
    }
    ll num1 = N / 3;
    ll num2 = num1 + 1;

    if (num1 + (2 * num2) != N)
    {
        swap(num1, num2);
    }

    cout << num1 << " " << num2 << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}