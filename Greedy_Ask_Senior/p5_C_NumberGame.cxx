#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://codeforces.com/problemset/problem/1749/C
void f()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    for (ans = (n + 1) / 2; ans; ans--)
    {
        int f = 1;
        for (int i = 1; i <= ans && f; i++)
            if (a[i + ans - 1] > i)
                f = 0;
        if (f)
            break;
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t;

    while (t--)
    {
        f();
    }

    return 0;
}