#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// bfs
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &gr)
    {
        int n = gr.size();
        vector<int> colour(n, 0);

        for (int node = 0; node < n; node++)
        {
            if (colour[node] != 0)
                continue;

            queue<int> q;
            q.push(node);
            colour[node] = 1;

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int ne : gr[cur])
                {
                    if (colour[ne] == 0)
                    {
                        colour[ne] = -colour[cur];
                        q.push(ne);
                    }
                    else if (colour[ne] != -colour[cur])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

bool dfs(int node, int color, vector<vector<int>> graph, vector<int> &vis)
{
    vis[node] = color;

    for (auto adjnode : graph[node])
    {
        if (vis[adjnode] == -1)
        {
            if (dfs(adjnode, !color, graph, vis) == false)
                return false;
        }
        else if (vis[adjnode] == color)
        {
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> vis(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            if (dfs(i, 1, graph, vis) == false)
                return false;
        }
    }

    return true;
}