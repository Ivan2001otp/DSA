#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> adj(N, vector<bool>(N));

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (adj[i][j] && adj[j][k] && adj[k][i])
                {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;
    return;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}