#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;

    unordered_map<char, int> mp;

    for (auto a : s)
        mp[a]++;

    int cnt = 0;
    for (auto a : mp)
    {
        if (a.second >= 2)
            cnt++;
    }

    if (cnt >= 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
