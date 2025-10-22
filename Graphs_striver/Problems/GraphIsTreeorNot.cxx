#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isCycle(vector<int> &vis, vector<vector<int>> adj, int node, int parent)
{

    vis[node]=1;

    for(auto adjnode : adj[node]) {

        if (!vis[adjnode]) {
            if (isCycle(vis, adj, adjnode, node))return true;
            else if (parent != adjnode)return true;
        }
    }

    return false;
}


int isTree(int n, int m, vector<vector<int>> &adj)
{

    vector<vector<int>> graph(n);

    for (auto e : adj)
    {
        int u = e[0];
        int v = e[1];

        if (u == v)
            return 0;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

   
    vector<int>vis(n, 0);
    if (isCycle(vis, graph, 0, -1)) return 0;

    for(int i=0;i<n;i++) {
        if (!vis[i])return 0;
    }

    return 1;
}

int main()
{
    vector<vector<int>> adj = {{0, 1}, {1, 2}, {1, 3}};
    int edges = adj.size();
    int nodes = edges + 1;

    if (isTree(nodes, edges, adj))
    {
        cout << "Is Tree" << endl;
    }
    else
    {
        cout << "Not Tree" << endl;
    }

    return 0;
}