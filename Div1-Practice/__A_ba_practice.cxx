// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int val = 0;
    int powt = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        val += pow(26, powt) * (s[i] - 'A' + 1);
        powt += 1;
    }

    cout << val << endl;
}

void solve3()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 0));

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u][v] = graph[v][u] = 1;
    }

    int c = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            for (int k = j + 1; k < V; k++)
            {
                if (graph[i][j] && graph[j][k])
                {
                    c++;
                }
            }
        }
    }

    cout << c << endl;
}

bool cmp1(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{

    if (p1.first.first != p2.first.first)
    {
        return p1.first.first > p2.first.first;
    }
    return p1.second < p2.second;
}

bool cmp2(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    if (p1.first.second != p2.first.second)
        return p1.first.second > p2.first.second;
    return p1.second < p2.second;
}

bool cmp3(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    if (p1.first.first + p1.first.second != p2.first.first + p2.first.second)
    {
        return p1.first.first + p1.first.second > p2.first.first + p2.first.second;
    }
    return p1.second < p2.second;
}

bool cmp4(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    return p1.second < p2.second;
}

void solve5()
{
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<pair<pair<int, int>, int>> v(N);

    for (int i = 0; i < N; i++)
    {
        int u;
        v[i].first.first = u;
    }

    for (int i = 0; i < N; i++)
    {
        int u;
        v[i].first.second = u;
    }

    for (int i = 0; i < N; i++)
    {
        v[i].second = i;
    }

    sort(v.begin(), v.end(), cmp1);
    sort(v.begin() + X, v.end(), cmp2);
    sort(v.begin() + X + Y, v.end(), cmp3);
    sort(v.begin(), v.begin() + X + Y + Z, cmp4);
}

void solve2()
{
    int X, K;
    cin >> X >> K;

    int pt = 1;

    for (int i = 1; i <= K; i++)
    {
        X = X / pt;

        int last = X % 10;

        if (last <= 4)
        {
            X -= last;
        }
        else
        {
            X += (10 - last);
        }

        X = X * pt;
        pt = pt * 10;
    }

    cout << X << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve3();
    }
    return 0;
}