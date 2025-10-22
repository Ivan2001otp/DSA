#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    int pos = -1;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        cout << "NO" << endl;
        return;
    }

    int l = pos - 1;
    int r = pos + 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (l >= 0 && s[l] == char(i + 'a'))
        {
            l--;
        }
        else if (r < s.size() && s[r] == char(i + 'a'))
        {
            r++;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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