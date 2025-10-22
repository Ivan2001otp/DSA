#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int dx[] = {-1, 1, 0, -1, 0, 1, 1, -1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
void solve()
{
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    rep(i, H) cin >> s[i];

    string T = "snuke";

    rep(i, H)
    {
        rep(j, W)
        {
            rep(k, 8)
            {
                int si = i;
                int sj = j;
                rep(l, 5)
                {
                    if (si < 0 || sj < 0 || si >= H || sj >= W)
                        break;
                    if (s[si][sj] != T[l])
                        break;

                    if (l == 4)
                    {
                        si = i;
                        sj = j;
                        rep(x, 5)
                        {
                            cout << si + 1 << " " << sj + 1 << endl;
                            si += dx[k], sj += dy[k];
                        }
                        return;
                    }
                    si = si + dx[k];
                    sj = sj + dy[k];
                }
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
        solve();
    }
    return 0;
}