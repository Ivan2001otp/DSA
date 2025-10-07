#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// bfs 
class Solution {
    public : 

    bool isCyclic( int v, vector<int>adj[]) {

        vector<int>indegree(v, 0);
        for(int i=0;i<v;i++) {
            for(auto node : adj[i]) {
                indegree[node]++;
            }
        }


        queue<int>q;
        for(int i=0; i < v; i++) {
            if (indegree[i]==0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while(! q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto adjnode : adj[node]) {
                indegree[adjnode]--;

                if (indegree[adjnode]==0) {
                    q.push(adjnode);
                }
            }
        }

        return cnt == v ;

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