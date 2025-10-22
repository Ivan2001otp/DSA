#include <bits/stdc++.h>

using namespace std;

int f3(vector<vector<int>> &adj) {
    int n = adj.size();

    int j = n-1;
    int i=0;

    while(i<j) {

        if (adj[j][i]) {
            j--;
        } else {
            i++;
        }
    }

    int c = i;
    for(int k=0;k<n;k++) {
        if (k == c ) continue;
        if (adj[c][i] || !adj[i][c])return -1;
    }

    return c;
}

int f2(vector<vector<int>> &adj) {

    int n = adj.size();
    stack<int>st;

    for(int i=0;i<n;i++){
        st.push(i);
    }

    while(st.size() >1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (adj[a][b]) {
            //a knows b
            st.push(b);
        } else {
            st.push(a);
        }
    }


    int celebrity = st.top();

    for(int i=0;i<n;i++) {
        if (i==celebrity)continue;
        
        if (adj[celebrity][i] || adj[i][celebrity]==0) {
            return -1;
        }
    }

    return celebrity;


}


int celebrityFinder(vector<vector<int>> &adj) {

    int n = adj.size();

    vector<int>indegree(n, 0);
    vector<int>outdegree(n, 0);

    for(int i=0;i < n;i++) {
        for(int j=0;j<n;j++) {
            if (adj[i][j]) {
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }


    for(int i=0;i < n; i++) {
        if (indegree[i]==n && outdegree[i]==1) return i;
    }

    return -1;
}