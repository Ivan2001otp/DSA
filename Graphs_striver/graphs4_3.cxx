#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> dist(n + 1, 1e9);
    vector<pair<int, int>> adj[n];

    for (auto a : flights)
    {
        adj[a[0]].push_back({a[1], a[2]});
    }

    queue<pair<int, pair<int, int>>> q;

    // node,{cost, k}
    q.push({src, {0, 0}});
    dist[src] = 0;

    while (!q.empty())
    {
        auto item = q.front();
        q.pop();

        int node = item.first;
        int curr_cost = item.second.first;
        int stops = item.second.second;

        if (stops > k)
            continue;

        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int cost = it.second;

            if (dist[adjnode] > cost + curr_cost)
            {
                dist[adjnode] = cost + curr_cost;
                q.push({adjnode, {dist[adjnode], stops + 1}});
            }
        }
    }

    return dist[dst] != 1e9 ? dist[dst] : -1;
}

int main()
{
    vector<vector<int>> f = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0, dst = 2, k = 1;
    cout << findCheapestPrice(3, f, src, dst, k);
    return 0;
}