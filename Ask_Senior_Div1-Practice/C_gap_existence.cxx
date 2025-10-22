#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, X;
    cin >> N >> X;

    unordered_map<int, int> mp;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    for (auto a : v)
    {
        mp[a] = 1;
    }

    for (auto a : v)
    {
        if (mp[a - X])
        {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
    return;
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