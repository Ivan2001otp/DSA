#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int node, vector<bool> &vis, vector<int> &ans, vector<int> adj[])
{
    vis[node] = true;
    ans.push_back(node);

    for (auto neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour, vis, ans, adj);
        }
    }
}

void solve()
{

    int V, E;
    cin >> V >> E;

    if (E == 0)
    {
        for (int i = 1; i <= V; i++)
        {
            cout << i << " ";
        }
        return;
    }

    vector<int> adj[V + 2];

    vector<int> a(E);
    for (int i = 0; i < E; i++)
        cin >> a[i];

    for (int i = 0; i < E; i++)
    {
        adj[a[i]].push_back(a[i] + 1);
    }

    vector<bool> vis(V + 2, false);
    vector<int> res;

    for (int i = 1; i <= V; i++)
    {
        vector<int> ans;
        if (!vis[i])
        {
            // cout << "i+1:" << i << endl;
            dfs(i, vis, ans, adj);
            reverse(ans.begin(), ans.end());
            // cout << "i+2:" << i << endl;
            for (auto a : ans)
            {
                res.push_back(a);
            }
        }
    }

    for (auto a : res)
    {
        cout << a << " ";
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