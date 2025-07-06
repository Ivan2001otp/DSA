#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int edges;
    cin >> edges;

    vector<int> adj[edges + 1];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
    }

    unordered_map<int, int> mp;

    int maxi = INT_MIN;
    for (vector<int> it : adj)
    {
        int s = it.size();
        maxi = max(s, maxi);
    }

    cout << maxi << endl;
}