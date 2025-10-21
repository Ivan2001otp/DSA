#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1759/C
void f()
{
    int l, r, x;
    cin >> l >> r >> x;
    int a, b;
    cin >> a >> b;

    if (a > b)
    {
        swap(a, b);
    }
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }

    if (abs(b - a) >= x)
    {
        cout << 1 << endl;
        return;
    }
    else if (r - b >= x)
    {
        cout << 2 << endl;
        return;
    }
    else if (a - l >= x)
    {
        cout << 2 << endl;
        return;
    }

    if (b - l >= x && r - a >= x)
    {
        cout << 3 << endl;
        return;
    }

    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}