#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// bellman ford algorithm - O(V*E)
vector<int>bellmanford(int V, vector<vector<int>>&edges, int S) {
    vector<int> dist(V, 1e8);
    // relax nodes n-1 times.
    dist[S] = 0;
    for(int i=0;i<V-1;i++) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] + wt < dist[v] && dist[u] != 1e8) {
                dist[v] = dist[u] + wt; 
            }
        }
    }

    // if the distance reduces in nth time then the graph has cycle.
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] + wt < dist[v] && dist[u] != 1e8) {
            return {-1};
        }
    }

    return dist;

}