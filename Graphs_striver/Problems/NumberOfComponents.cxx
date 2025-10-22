
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
class Solution {
  public:
    
    
    void dfs(int node, vector<vector<int>>&adj, vector<int>&temp, unordered_map<int,bool>&vis) {
        vis[node]=true;
        
        temp.push_back(node);
        
        for(auto adjnode : adj[node]) {
            if (! vis[adjnode]) {
                dfs(adjnode, adj, temp, vis);
            }
        }
        
        return;
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
    {
        // code here
    
        vector<vector<int>> adj(V);
    
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    
        vector<vector<int>>ans;
        unordered_map<int, bool> visited;
        
        for(int i=0;i<V;i++) {
            if (! visited[i]) {
                vector<int>t;
                dfs(i, adj, t, visited);
                ans.push_back(t);
            }
        }
        
        
    
        return ans;
    }
};
