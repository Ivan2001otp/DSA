#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    map<char, int> mp;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    vector<pair<char, int>> v;

    for (auto a : mp)
    {
        v.push_back({a.first, a.second});
    }

    sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return (a.first - 65) < (b.first - 65); });

    for (auto a : v)
    {
        cout << a.first << " " << a.second << endl;
    }

    return 0;
}