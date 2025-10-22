#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void f(int index, char *prev, string s, vector<string> &V)
{

    if (index < 0)
    {
        // cout << s << endl;
        V.push_back(s);
        return;
    }

    if (prev == nullptr)
    {
        if (s[index] == '?')
        {
            s[index] = 'B';
            f(index - 1, &(s[index]), s, V);

            s[index] = 'R';
            f(index - 1, &(s[index]), s, V);
        }
        else
        {
            f(index - 1, &(s[index]), s, V);
        }
    }
    else
    {

        if (s[index] == '?')
        {
            if (s[index + 1] == 'R')
            {
                s[index] = 'B';
                f(index - 1, &(s[index]), s, V);
            }
            else if (s[index + 1] == 'B')
            {
                s[index] = 'R';
                f(index - 1, &(s[index]), s, V);
            }
        }
        else
        {
            f(index - 1, &(s[index]), s, V);
        }
    }
}

void solve()
{
    int N;
    cin >> N;

    string s;
    cin >> s;
    vector<string> V;
    f(N - 1, nullptr, s, V);

    int cost = 1e9;
    string res = "";
    for (int i = 0; i < V.size(); i++)
    {
        string s = V[i];
        int cnt = 0;
        for (int j = 0; j < s.size() - 1; j++)
        {
            if (s[j] == s[j + 1])
                cnt++;
        }
        if (cost > cnt)
        {
            cost = cnt;
            res = s;
        }
    }

    cout << res << endl;
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
