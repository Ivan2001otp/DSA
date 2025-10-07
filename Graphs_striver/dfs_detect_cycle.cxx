#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool detect(int node, int parent, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto adjacent : adj[node])
    {
        if (!vis[adjacent])
        {
            if (detect(adjacent, node, vis, adj))
                return true;
        } else if (node != parent) {
            return true;
        }
    }

    return false;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool> vis(v);

    for (int i = 0; i < v; i++)
    {
        if (detect(i, -1, vis, adj))
        {
            return true;
        }
    }

    return false;
}



bool detect2(int node, int parent, vector<int>& vis, vector<int>adj[]) {
    vis[node]=1;

    for(auto a : adj[node]) {

        if (!vis[a]) {
            if (detect2(a, node, vis, adj))return true;
            
        } else if (node != parent) {
            return true;
        }
    }

    return false;
}

bool isCycle2(int v , vector<int>adj[]) {
    vector<int>vis(v, 0);

    for(int i=0; i<v; i++) {
        if (! vis[i]) {
            if (detect2(i, -1, vis, adj)) return true;
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