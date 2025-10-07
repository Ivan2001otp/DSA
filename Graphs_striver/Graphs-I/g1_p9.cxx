#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
    private : 
    void findTopoSort(int node,vector<int>vis, vector<int>adj[], stack<int>&st) {
        
        vis[node] = 1;

        for(auto adjnode : adj[node]) {
            if (!vis[adjnode]) {
                findTopoSort(adjnode, vis, adj, st);
            }
        }

        st.push(node);
    }

    public :
    vector<int> topoSort(int N, vector<int>adj[]) {
        stack<int>st;
        vector<int>v(N, 0);

        for(int i=0;i < N ;i++) {
            if (!v[i]) {
                findTopoSort(i, v, adj, st);
            }
        }


        vector<int>v;

        while(! st.empty()) {
            v.emplace_back(st.top());
            st.pop();
        }

        return v;
    }
};