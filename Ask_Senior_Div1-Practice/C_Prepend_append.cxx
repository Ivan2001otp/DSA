#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    string s;
    cin >> s;

    int i = 0;
    int j = N - 1;

    if (N == 1)
    {
        cout << 1 << endl;
        return;
    }

    while (s[i] != s[j])
    {
        i++, j--;
    }

    if (j < i)
    {
        cout << 0 << endl;
    }
    else
        cout << j - i + 1 << endl;
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
