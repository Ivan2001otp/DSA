#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(vector<int> adj[], int node, vector<int> &vis)
{
    vis[node] = 1;

    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        auto currNode = q.front();
        q.pop();

        for (auto adjnode : adj[currNode])
        {
            if (!vis[adjnode])
            {
                vis[adjnode] = 1;
                q.push(adjnode);
            }
        }
    }
}

void solve()
{
    int N, M;
    cin >> N >> M;

    if (M == 0)
    {
        cout << N << endl;
        return;
    }
    vector<int> adj[N + 1];
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(N + 1, false);

    int c = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            c++;
            bfs(adj, i, vis);
        }
    }

    cout << c << endl;
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