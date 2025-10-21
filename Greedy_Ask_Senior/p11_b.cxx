#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1797/B
void f()
{
    int n, k;
    cin >> n >> k;

    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    if (n == 1)
    {
        cout << "Yes" << endl;
        return;
    }

    int old, after;
    int req = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            old = arr[i][j];
            after = arr[n - i - 1][n - j - 1];

            req += (old != after);
        }
    }

    req = req / 2;

    if (req > k)
    {
        cout << "No" << endl;
        return;
    }

    req = req - k;

    if (n & 1)
    {
        cout << "Yes" << endl;
        return;
    }

    if (req & 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
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