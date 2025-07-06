#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> bfs(vector<vector<int>> &adj)
{
    int V = adj.size();
    int source = 0;
    vector<bool> vis(V, false);
    queue<int> q;

    vis[source] = 1;
    q.push(source);
    vector<int> res;

    while (!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();

        for (auto it : adj[curr])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    for (auto a : res)
        cout << a << " ";
    return res;
}

void solve()
{
    vector<vector<int>> v = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    vector<int> arr = bfs(v);
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