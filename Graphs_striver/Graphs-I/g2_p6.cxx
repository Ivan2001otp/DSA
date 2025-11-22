#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// DSU - to find whether the nodes belong to the same component or not.


    Node* cloneGraph(Node* node) {

       if (node==nullptr) {
         return NULL;
       } 

       if (node->neighbors.size()==0)  {
            Node* clone = new Node(node->val);
            return clone;
       }

       return dfs(node, mp);
    };




class DisjointSet {
    vector<int>rank, parent;

    public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }


    // find parent
    int findParent(int node) {

        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }


    // union by rank
    void unionByRank(int u, int v) {
        int ultimate_parent_u = findParent(u);
        int ultimate_parent_v = findParent(v);

        if (ultimate_parent_u == ultimate_parent_v) return;

        if (rank[ultimate_parent_u] < rank[ultimate_parent_v]) {
            parent[ultimate_parent_u] = ultimate_parent_v;
        } else if (rank[ultimate_parent_u] > rank[ultimate_parent_v]) {
            parent[ultimate_parent_v] = ultimate_parent_u;
        } else {
            parent[ultimate_parent_u] = ultimate_parent_v;
            rank[ultimate_parent_v]++;
        }
    }
};

int main() {
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if (ds.findParent(3) == ds.findParent(7)) {
        cout<<"Same"<<endl;
    }
}