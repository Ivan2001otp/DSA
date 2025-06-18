#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    string s;
    cin >> s;

    char ch = 'z';
    int index = -1;

    for (int i = 0; i < N; i++)
    {
        if (ch - 'a' + 1 > s[i] - 'a' + 1)
        {
            ch = s[i];
            index = i;
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (s[i] == ch)
        {
            string t = "";
            t = ch + s.substr(0, i) + s.substr(i + 1);
            cout << t << endl;
            break;
        }
    }

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
}