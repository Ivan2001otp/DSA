#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;

    cin >> s;
    int c = 0;
    vector<char> v;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1')
        {
            c++;
            if (c % 2 == 0)
            {
                v.push_back('+');
            }
            else
            {
                v.push_back('-');
            }
        }
        else
        {
            v.push_back('+');
        }
    }

    for (auto a : v)
    {
        cout << a;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}