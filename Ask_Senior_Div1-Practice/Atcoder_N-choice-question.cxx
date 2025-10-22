#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        mp[v[i]] = i + 1;
    }

    cout << mp[A + B] << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}