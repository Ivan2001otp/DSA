#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {

    private : 
    bool detect(int src, vector<int>adj[], vector<int>& vis) 
    {
        vis[src] = 1;
        // source, parent
        queue<pair<int,int>>q;
        
        q.push({1, -1});

        while(!q.empty()) {
            
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();


            for(auto a : adj[node]) {
                if (!vis[a]) {
                    vis[a] = 1;
                    q.push({a, node});
                } else if (parent != a) {
                    // not its own parent.
                    return true;
                }
            }
        }

        return false;
    }


    public : 
    bool isCyclic(int V, vector<int>adj[]) {
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis))return true;
            }
        }

        return false;
    }
};

bool detect(vector<int>& vis, int node, vector<int>adj[]) {

    queue<pair<int,int>>q;
    q.push({node,-1});

    vis[node]=1;


    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int currnode = curr.first;
        int parent = curr.second;

        for(auto n : adj[currnode]) {

            if (!vis[n]) {
                vis[n] = 1;
                q.push({n, currnode});
            } else if(parent != n) {
                return true;
            }
        }
    }
    return false;

}

bool isCyclic(int v ,vector<int>adj[]) {
    vector<int>vis(v, 0);
    for(int i=0;i<v;i++) {
        if (!vis[i]) {
            if(detect(vis,i,adj)) return true;
        }
    }

    return false;
}

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}