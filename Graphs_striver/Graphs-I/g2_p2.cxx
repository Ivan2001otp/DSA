#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// return shortest path
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {

    vector<pair<int,int>> adj[n+1];
    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>dist(n+1, 1e9+1), parent(n+1, 0);
    for(int i=1;i<=n;i++) {
        parent[i] = i;
    }

    dist[1] = 0;//starting from 1 node.

    // dist, node
    pq.push({0, 1});

    while(! pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int currDist = it.first;

        for(auto it : adj[node]) {

            int adjNode = it.first;
            int nextWt = it.second;


            if (currDist + nextWt < dist[adjNode]) {
                dist[adjNode] = currDist + nextWt;
                pq.push({currDist + nextWt, adjNode});

                // where r u coming from.
                parent[adjNode] = node;
            }
        }
    }


    if (dist[n] == 1e9) {
        return {-1};
    }

    vector<int>path;
    int node = n;

    while(parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());
    return path;
}