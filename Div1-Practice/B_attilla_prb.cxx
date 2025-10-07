#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int max_num = 0;
    for (int i = 0; i < n; i++)
    {
        max_num = max(max_num, s[i] - 'a' + 1);
    }

    cout << "res : " << max_num << endl;
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
