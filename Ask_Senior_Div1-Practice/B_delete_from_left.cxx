#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s, t;
    cin >> s >> t;

    int i = s.size() - 1;
    int j = t.size() - 1;

    while (i >= 0 && j >= 0)
    {
        if (s[i] != t[j])
            break;

        i--, j--;
    }
    int cnt = 0;
    if (i >= 0)
    {
        cnt += (i + 1);
    }

    if (j >= 0)
    {
        cnt += (j + 1);
    }
    cout << cnt << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}