#include <bits/stdc++.h>
using namespace std;
#define nl endl;

// https://leetcode.com/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06
class Solution
{
public:
    void dfs(int node, int par, vector<int> adj[], vector<int> &parent,
             vector<int> &vis, unordered_map<int, set<int> > &mp)
    {

        vis[node] = 1;
        mp[par].insert(node);
        parent[node] = par;

        for (auto nei : adj[node])
        {
            if (!vis[nei])
            {
                dfs(nei, par, adj, parent, vis, mp);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int> > &connections,
                               vector<vector<int> > &queries)
    {

        vector<int> vis(c + 1, 0);
        vector<int> adj[c + 1];

        vector<int> online(c + 1, 1);
        unordered_map<int, set<int> > mp;

        vector<int> superPar(c + 1, 0);
        vector<int> res;

        for (auto a : connections)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }

        for (int i = 1; i <= c; i++)
        {
            if (!vis[i])
            {
                dfs(i, i, adj, superPar, vis, mp);
            }
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int type = queries[i][0];
            int n = queries[i][1];

            int superParent = superPar[n];

            if (type == 2)
            {

                online[n] = 0;
                mp[superParent].erase(n);
            }
            else
            {

                if (online[n])
                {
                    res.push_back(n);
                }
                else
                {
                    if (mp[superParent].size() > 0)
                    {
                        res.push_back(*mp[superParent].begin());
                    }
                    else
                    {
                        res.push_back(-1);
                    }
                }
            }
        }

        return res;
    }
};