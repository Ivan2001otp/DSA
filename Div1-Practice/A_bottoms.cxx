#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'v')
        {
            cnt += 1;
        }
        else
        {
            cnt += 2;
        }
    }

    cout << cnt << endl;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}