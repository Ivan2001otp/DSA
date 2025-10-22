#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// prims algorithm.
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int>vis(V, 0);

    priority_queue<pair<int,    int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // {wt, node}
    pq.push({0, 0});

    int sum = 0;
    while(! pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int currnode = it.second;
        int currwt = it.first;

        if (vis[currnode]) {
            continue;
        }

        sum += currwt;

        for(auto k : adj[currnode]) {
            int adjnode = k[0];
            int edge = k[1];
            if (! vis[adjnode]) {
                pq.push({edge, adjnode});
            }
        }
    }

    return sum;
}