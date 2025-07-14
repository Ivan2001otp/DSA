#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    string s;
    cin >> s;
    if (N == 1)
    {
        cout << "Yes" << endl;
        return;
    }
    else if (N == 2)
    {
        if (s[0] != s[1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return;
    }

    unordered_map<char, int> mp;

    mp[s[0]] = 1;
    bool exit = false;

    for (int i = 1; i < N; i++)
    {
        if (s[i] == s[i - 1])
        {
            cout << "No" << endl;
            exit = true;
            break;
        }
        else
        {
            if (mp.count(s[i]) == 0)
            {
                mp[s[i]] = !mp[s[i - 1]];
            }
            else
            {
                if (mp[s[i]] == mp[s[i - 1]])
                {
                    exit = true;
                    cout << "No" << endl;
                    break;
                }
            }
        }
    }
    if (exit)
        return;
    cout << "Yes" << endl;
    return;
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
