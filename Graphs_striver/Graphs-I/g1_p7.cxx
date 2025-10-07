#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    public : 
    // dfs
    bool detect(int node, int vis[], int pathVis[], vector<int>adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]) {
            if (! vis[it]) {
                if (detect(it, vis, pathVis, adj))return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node]=0;
        
        return false;
    }

    bool isCyclic( int v, vector<int>adj[]) {

        int vis[v] = {0};
        int pathVis[v] = {0};

        for(int i=0;i<v;i++) {
            if (!vis[i]) {
                if (detect(i, vis, pathVis, adj))return true;
            }
        }

        return false;

    }
};

int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
	int V = 6;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);
	if (ans) cout << "True";
	else cout << "Flase";
	cout << endl;
	return 0;
}