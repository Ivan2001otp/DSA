#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct cmp
{
    constexpr bool operator()(pair<int, int> &a, pair<int, int> &b) const noexcept
    {
        return a.second < b.second;
    }
};

void solve1()
{

    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v[i] = {a, b};
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i].first < v[i].second)
        {
            ++count;
        }
    }

    cout << count << endl;
    return;
}

void solve2()
{
    string S, T;
    cin >> S >> T;

    unordered_map<char, int> mp;
    for (int i = 0; i < T.size(); i++)
    {
        mp[T[i]]++;
    }

    for (int i = 1; i < S.size(); i++)
    {
        if (S[i] - 'a' < 0)
        {
            if (!mp[S[i - 1]])
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}

void solve3()
{
    int n;
    cin >> n;
    vector<int> S(n);
    for (int &s : S)
        cin >> s;

    if (S.size() >= 4)
        sort(S.begin() + 1, S.end() - 1);

    vector<int> A(n, 0);
    A[0] = 1;
    int x = S[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (x * 2 >= S[n - 1])
            break;
        if (S[i] <= x * 2 && S[i + 1] > x * 2)
        {
            A[i] = 1;
            x = S[i];
        }
    }
    if (S[n - 1] <= x * 2)
    {
        A[n - 1] = 1;
        int ans = 0;
        for (int i : A)
            ans += i;
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

void solve4()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V + 1];
    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> indegree(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        for (auto adjnode : adj[i])
        {
            indegree[adjnode]++;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 1; i <= V; i++)
    {
        pq.push({i, indegree[i]});
    }

    while (!pq.empty())
    {
       int node = pq.top().first;
       int degree = pq.top().second;

       pq.pop();

       for(auto adjnode : adj[node]) {
            if (indegree[adjnode]>2) {
                indegree[adjnode]--;
                indegree[node]--;
            }
       }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve4();
    }
    return 0;
}