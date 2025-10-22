#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string S;
    cin >> S;

    reverse(S.begin(), S.end());

    ll res = 0;
    ll p = 0;
    for (int i = 0; i < S.size(); i++)
    {
        res += ((S[i] - 'A' + 1) * pow(26, p));
        p++;
    }

    cout << res << endl;
    return;
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