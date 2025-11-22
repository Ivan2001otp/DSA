#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool detect(int node, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({node, -1});

    vis[node] = 1;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int adjnode = curr.first;
        int parent = curr.second;

        for (auto neighbour : adj[adjnode])
        {
            if (!vis[neighbour])
            {
                vis[neighbour] = 1;
                q.push({neighbour, adjnode});
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }

        return false;
    }
}

// bfs
bool isCycle(int N, vector<int> adj[])
{
    vector<int> vis(N, 0);

    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
            {
                return true;
            }
        }
    }

    return false;
}

class T1
{
public:
    bool detectV2(int source, vector<int> adj[], vector<bool> &vis)
    {
        queue<pair<int, int>> q;
        vis[source] = 1;
        q.push({source, -1});

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            int parent = p.second;
            int adjacentnode = p.first;

            for (auto neighbour : adj[adjacentnode])
            {
                if (!vis[neighbour])
                {
                    vis[neighbour] = 1;
                    q.push({neighbour, adjacentnode});
                }
                else if (parent != adjacentnode)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

bool isCycle(int N, vector<int> adj[])
{
    vector<bool> vis(N);
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
                return true;
        }
    }

    return false;
}

int main()
{

    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}