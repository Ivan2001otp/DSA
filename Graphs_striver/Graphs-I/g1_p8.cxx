#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> topSortBfs(int v, vector<int>adj[]) {
    vector<int>indegree(v,0);

    for(int i=0;i<v;i++) {
        for(auto adjnode : adj[i]) {
            indegree[adjnode]++;
        }
    }

    queue<int>q;
    for(int i=0;i<v;i++) {
        if (indegree[i]==0)q.push(i);
    }

    vector<int>topo;
    while(!q.empty()) {

        int ele = q.front();
        q.pop();

        topo.push_back(ele);

        for(auto adjnode : adj[ele]) {
            indegree[adjnode]--;

            if (indegree[adjnode]==0){
                q.push(adjnode);
            }
        }


    }

    return topo;
}