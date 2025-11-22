#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int findTheCity(int n, vector<vector<int>> &edges, int dt)
{

    vector<vector<int>> dg(n, vector<int>(n, 1e5 + 10));
    int res = 0;

    // creating Directed graph
    for (auto &a : edges)
    {
        dg[a[0]][a[1]] = dg[a[1]][a[0]] = a[2];
    }

    for (int i = 0; i < n; i++)
    {
        dg[i][i] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dg[i][j] = min(dg[i][k] + dg[k][j], dg[i][j]);
            }
        }
    }

    int smallest = n;
    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (dg[i][j] <= dt)
            {
                count++;
            }
        }

        if (count <= smallest)
        {
            res = i;
            smallest = count;
        }
    }

    return res;
}

int dijkshtraV2(int n, vector<pair<int, int>> graph[], int src, int dt)
{
    vector<int> dist(n + 1, 1e9);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    dist[src] = 0;
    pq.push({src, 0}); // node,dist
    int count = 0;

    while (!pq.empty())
    {
        auto item = pq.top();
        pq.pop();

        int currNode = item.first;
        int currDist = item.second;

        if (dist[currNode] < currDist)
            continue;

        for (auto adj : graph[currNode])
        {

            int adjnode = adj.first;
            int nextDist = adj.second;

            if (dist[currNode] + nextDist < dist[adjnode])
            {
                dist[adjnode] = dist[currNode] + nextDist;
                pq.push({adjnode, dist[adjnode]});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] <= dt)
        {
            count++;
        }
    }

    return count;
}

int dijkshtra(int n, vector<pair<int,int>> graph[], int src,int dt) {

    vector<int>dist(n, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({src, 0});
    dist[src]=0;

    while(! pq.empty()) {
        int currDist = pq.top().second;
        int currNode = pq.top().first;

        if (currDist > dist[currNode])continue;

        for(auto &adj : graph[currNode]) {
            int adjnode = adj.first;
            int nextDist = adj.second;

            if (currDist + nextDist < dist[adjnode]) {
                dist[adjnode] = currDist + nextDist;
                pq.push({adjnode, dist[adjnode]});
            }
        }
    }
    int c = 0;
    for(int i=0;i<n;i++) {
        if (dist[i]<=dt){
            c++;
        }
    }

    return c;
}

void f(int n, vector<vector<int>> &edges, int dt)
{
    vector<pair<int, int>> graph[n + 1];

    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int count = dijkshtra(n, graph, i, dt);

        mini = min(count, mini);
    }

    // cout << " Node : " << node << endl;
}

int findTheCity(int n, vector<vector<int>> &edges, int dt)
{
    vector<pair<int, int>> adj[n + 1];

    for (auto &e : edges)
    {
        adj[e[0]].push_back({e[1], e[2]});
    }

    int mini = INT_MAX;
    for(int i=0;i<n;i++) {
        int count = dijkshtra(n, adj, i, dt);
        mini = min(count, mini);

    }

}

int main()
{
    int N = 6;
    vector<vector<int>> edges(N, vector<int>(3));
    edges[0] = {0, 1, 2};
    edges[1] = {0, 4, 8};
    edges[2] = {1, 2, 3};
    edges[3] = {1, 4, 2};
    edges[4] = {2, 3, 1};
    edges[5] = {3, 4, 1};

    int dist = 2;
    // cout << findTheCity(N, edges, dist);
    f(N, edges, dist);
    return 0;
}