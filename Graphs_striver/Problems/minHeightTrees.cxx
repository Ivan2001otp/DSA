#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://leetcode.com/problems/minimum-height-trees/?envType=problem-list-v2&envId=graph
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{

    if (n == 1)
        return {0};

    vector<vector<int>> adj(n);

    vector<int> indegree(n);

    /*
    for (auto& e : edges){
            adj[e[0]] ^= e[1]; idg[e[0]]++;
            adj[e[1]] ^= e[0]; idg[e[1]]++;
        }
    */
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        ++indegree[e[0]];
        ++indegree[e[1]];
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 1)
        {
            q.push(i);
        }
    }

    int remaining = n;

    while (remaining > 2)
    {
        int leavesCount = q.size();
        remaining = remaining - leavesCount;

        for (int i = 0; i < leavesCount; i++)
        {
            int leaf = q.front();
            q.pop();

            // visit all adjacent nodes
            for (auto adjnode : adj[leaf])
            {
                if (--indegree[adjnode] == 1)
                {
                    q.push(adjnode);
                }
            }
        }
    }

    vector<int> res;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        res.push_back(element);
    }

    return res;
}