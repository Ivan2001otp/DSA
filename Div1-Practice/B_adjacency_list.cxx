#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, M;
    cin >> N >> M;
    int u, v;

    vector<int> adj[N + 1];

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        for (auto adjnode : adj[i])
        {
            v.push_back(adjnode);
        }
        sort(v.begin(), v.end());
        mp[i] = (v);
    }

    cout << endl
         << endl;

    for (int i = 0; i < N; i++)
    {
        cout << mp[i].size() << " ";
        
        for (int j = 0; j < mp[i].size(); j++)
        {

            cout << mp[i][j] + 1 << " ";
        }
        cout << endl;
    }
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