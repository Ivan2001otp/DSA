#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dijsktra(int src, int target, int v, vector<pair<int, int>> adj[])
{

    vector<int> dist(v + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src}); // dist, node;
    dist[src] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int curr_dist = pq.top().first;

        pq.pop();

        if (dist[node] < curr_dist)
            continue;

        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int wt = it.second;

            if (curr_dist + wt < dist[adjnode])
            {
                dist[adjnode] = curr_dist + wt;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    return dist;
}

int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges)
{
    vector<vector<int>> curved_graph;
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        int curved_wt = edges[i][3];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});

        curved_graph.push_back({u, v, curved_wt});
    }

    vector<int> da = dijsktra(a, b, n, adj);
    vector<int> db = dijsktra(b, a, n, adj);

    for (auto a : da)
        cout << a << " ";
    
    cout<<endl;
    for (auto a : db)
    {
        cout << a << " ";
    }
    int ans = db[a];

    for(auto it : curved_graph) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        ans = min(ans, da[u] + wt + db[v]);
        ans = min(ans, da[v] + wt + db[u]);
    }

    if (ans > 1e9) {
        return -1;
    }

    return ans;
}

int main()
{
    int V = 4, E = 4;
    int a = 2, b = 4;
    vector<vector<int>> edges = {{1, 2, 1, 4}, {1, 3, 2, 4}, {1, 4, 3, 1}, {2, 4, 6, 5}};
    shortestPath(V, E, a, b, edges);
    return 0;
}