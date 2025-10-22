#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (int neighbor : adj[i])
            {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        if (topo.size() != V)
        {
            return {};
        }

        return topo;
    }

    string findOrder(vector<string> &words)
    {
        vector<int> letterused(26, 0);
        int n = 0;
        for (auto word : words)
        {
            for (auto ch : word)
            {
                if (letterused[ch - 'a'] == 0)
                {
                    letterused[ch - 'a'] = 1;
                    n++;
                }
            }
        }

        vector<vector<int>> adj(26);

        for (int i = 0; i < words.size() - 1; i++)
        {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.length(), s2.length());
            bool found = false;

            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            if (!found && s1.size() > s2.size())
            {
                return "";
            }
        }

        vector<int> topo = topoSort(26, adj);
        if (topo.empty())
            return "";

        string ans = "";
        for (int i = 0; i < topo.size(); i++)
        {
            if (letterused[topo[i]])
            {
                ans += (char)(topo[i] + 'a');
            }
        }

        return ans;
    }
};