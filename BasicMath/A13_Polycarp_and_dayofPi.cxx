#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    const string ref = "314159265358979323846264338327";
    string s;
    cin >> s;
    int n = s.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ref[i])
        {
            c++;
        }
        else
        {
            break;
        }
    }

    cout << c << endl;
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