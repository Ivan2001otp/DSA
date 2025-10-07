#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
void dfs(vector<bool> &vis, int source, vector<vector<int>> &adj)
{
    if (vis[source])return;

    vis[source]=1;
    cout <<source<<" ";

    for(auto it : adj[source]) {
        if (!vis[it]) {
            dfs(vis, it, adj);
        }
    }
}

void solve()
{
    vector<vector<int>> v = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    int N = v.size();
    vector<bool> vis(N + 1, false);
    dfs(vis, 0, v);
}
*/

void dfs(vector<bool>&vis, int source,  vector<vector<int>> &adj) {

    if (vis[source])return;

    vis[source] = 1;

    for(auto it : adj[source]) {
        if (!vis[it])
        dfs(vis, it, adj);
    }
}

void solve() {
    vector<vector<int>> v = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    int N = v.size();
    vector<bool> vis(N+1, false);
    dfs(vis, 0, N);
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