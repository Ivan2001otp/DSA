#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    string s;
    cin >> s;
    int n = s.size();
    char ch;
    int code;
    for (int i = 0; i < n; i++)
    {
        ch = s[i] - 32;
        cout << ch;
    }
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}