#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    // code here
    vector<vector<pair<int, int>>> adj(V + 1);

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]}); // node, wt
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);

    dist[0] = 0;

    pq.push({0, 0}); // dist,node
    vector<int> res;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int curr_dist = pq.top().first;

        pq.pop();
        if (curr_dist > dist[node])
        {
            continue;
        }

        for (auto &it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (wt + curr_dist < dist[v])
            {
                dist[v] = wt + curr_dist;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1;
        }
        cout << dist[i] << " ";
    }

    return {};
}

int main()
{
    int V = 6, E = 7;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    shortestPath(V, E, edges);
    return 0;
}