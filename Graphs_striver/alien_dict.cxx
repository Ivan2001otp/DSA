#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string findOrder(vector<string> &str)
{
    // code here
    vector<vector<int>> adj(26, vector<int>());

    for (int i = 0; i <= str.size() - 2; i++)
    {
        string s1 = str[i];
        string s2 = str[i + 1];

        int l = 0, m = 0;

        while (l < s1.size() && m < s2.size())
        {

            if (s1[l] != s2[m])
            {
                adj[s1[l] - 'a'].push_back(s2[m] - 'a');
                break;
            }

            l++, m++;
        }
    }

    vector<int> indegree(str.size());

    for (int i = 0; i < 26; i++)
    {
        for (auto node : adj[i])
        {
            indegree[node]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < indegree.size() - 1; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> v;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        v.push_back(node);

        for (auto a : adj[node])
        {
            indegree[a]--;

            if (indegree[a] == 0)
            {
                q.push(a);
            }
        }
    }

    cout << v.size() << ", " << indegree.size() - 1 << endl;
    if (v.size() == indegree.size() - 1)
    {
        string tmp = "";
        for (auto a : v)
        {
            tmp.push_back((char)(a + 'a'));
        }
        return tmp;
    }

    return "";
}

void solve()
{
    vector<string> str = {"caa", "aaa", "aab"};
    cout << findOrder(str);
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t)
    {
        --t;
        solve();
    }
}