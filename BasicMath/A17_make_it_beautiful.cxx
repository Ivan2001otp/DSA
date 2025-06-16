#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> t;
    t.push_back(v[0]);

    for (int i = N - 1; i >= 1; i--)
    {
        t.push_back(v[i]);
    }

    if (t[0] == t[1])
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES " << endl;
        for (auto a : t)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}