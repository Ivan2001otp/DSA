#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<ll>> v(N, vector<ll>(M));
    vector<vector<ll>> ans(N + 1, vector<ll>(M + 1));

    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }

    // precompute
    ans[0][0] = v[0][0];

    for (ll i = 1; i < M; i++)
    {
        ans[0][i] = ans[0][i - 1] + v[0][i];
    }

    for (ll i = 1; i < N; i++)
    {
        ans[i][0] = ans[i - 1][0] + v[i][0];
    }

    for (ll i = 1; i < N; i++)
    {
        for (ll j = 1; j < M; j++)
        {
            ans[i][j] = v[i][j] + ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
        }
    }

    while (Q--)
    {
        ll del = 0;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        x1--,y1--,x2--,y2--;

        if (x1 != 0)
        {
            del += ans[x1 - 1][y2];
        }
        if (y1 != 0)
        {
            del += ans[x2][y1 - 1];
        }
        if (x1 != 0 && y1 != 0)
        {
            del -= ans[x1 - 1][y1 - 1];
        }

        cout << ans[x2][y2] - del << endl;
    }

    return 0;
}