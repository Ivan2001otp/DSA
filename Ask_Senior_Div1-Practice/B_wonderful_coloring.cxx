#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    vector<ll> hash(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    int ans = 0, one_cnt = 0;

    for (int i = 0; i < 26; i++)
    {
        if (hash[i] >= 2)
        {
            ans++;
        }
        else if (hash[i] == 1)
        {
            one_cnt++;
        }
    }

    ans += (one_cnt / 2);
    cout << ans << endl;
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