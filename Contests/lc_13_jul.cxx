#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// weekly contest 458.

string getReverse(string s)
{
    return string(s.rbegin(), s.rend());
}

string processStr(string s)
{

    int N = s.size();
    string temp = "";

    for (int i = 0; i < N; i++)
    {
        if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25)
        {
            temp.push_back(s[i]);
        }
        else if (s[i] == '*' && !temp.empty())
        {
            temp.pop_back();
        }
        else if (s[i] == '#')
        {
            string dup = temp;
            temp = temp + dup;
        }
        else if (s[i] == '%')
        {
            temp = getReverse(temp);
        }
    }

    if (temp.empty())
        cout << "Empty" << endl;
    else
        cout << "NotEmpty" << endl;
    return temp;
}

class Solution
{
public:
    vector<int> parent;

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        parent[px] = py;
        return true;
    }

    int minimumCost(int n, vector<vector<int>> &edges, int k)
    {
        // Step 1: Sort edges by weight
        sort(edges.begin(), edges.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        vector<int> mst_weights;

        for (auto &e : edges)
        {
            if (unite(e[0], e[1]))
            {
                mst_weights.push_back(e[2]);
            }
        }

        // Step 2: Remove (k-1) largest edges
        sort(mst_weights.begin(), mst_weights.end(), greater<int>());

        for (int i = 0; i < k - 1 && !mst_weights.empty(); ++i)
        {
            mst_weights.erase(mst_weights.begin());
        }

        return mst_weights.empty() ? 0 : mst_weights[0];
    }
};

signed int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // solve();
    }
    return 0;
}