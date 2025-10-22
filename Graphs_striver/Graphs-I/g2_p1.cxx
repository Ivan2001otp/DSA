#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
- Sort all the edges as per the finishing time.
- Reverse the graph edges
- do a DFS
*/

void dfs(int node, vector<int>&vis, vector<int>adj[], stack<int>st) {

    vis[node] = 1;
    for( auto adjnode : adj[node] ) {
        if (!vis[adjnode]) {
            dfs(adjnode, vis, adj, st);
        }
    }

    st.push(node);
}


void dfs2(int node, vector<int>&vis, vector<int>adj[]) {
    vis[node]=1;

    for(auto adjnode : adj[node]) {
        if (! vis[adjnode]) {
            dfs2(adjnode, vis, adj);
        }
    }
}

int kosaraju(int V, vector<int>adj[]) {
    vector<int>vis(V, 0);
    stack<int>st;

    for(int i=0;i<V;i++) {
        if (!vis[i]) { 
            dfs(i, vis, adj, st);
        }
    }

    // reverse the edges
    for(int i=0;i<V;i++) {
        vis[i]=0;
        for(auto it : adj[i]) {
            //i->it --- it->i
            adj[it].push_back(i);
        }
    }

    int count = 0;
    vector<vector<int>>res;
    while(! st.empty()) {
        int node = st.top();
        st.pop();
        vector<int>temp;

        if (! vis[node]) {
            ++count;
            dfs2(node, vis, adj);
        }
    }

    return count;
}