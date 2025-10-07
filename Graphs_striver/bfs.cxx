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

vector<int> bfs2(vector<vector<int>>&adj) {
    int V = adj.size();
    int source = 0;

    queue<int>q;
    vector<bool>vis(V+1, false);
    q.push(source);
    vis[source]=1;

    vector<int>res;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        res.push_back(curr);

        for(auto a : adj[curr]) {
            if (!vis[a]) {
                vis[a]=1;
                q.push(a);
            }
        }
    }
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