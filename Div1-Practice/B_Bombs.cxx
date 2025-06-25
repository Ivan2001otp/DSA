#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int R, C;
    cin >> R >> C;
    vector<string> mat(R);

    for (int i = 0; i < R; i++)
    {
        cin >> mat[i];
    }

    vector<string> ans(R, string(C, '#'));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] != '.' && mat[i][j] != '#')
            {

                for (int l = 0; l < R; l++)
                {
                    for (int m = 0; m < C; m++)
                    {
                        if (abs(l - i) + abs(m - j) <= (mat[i][j] - '0'))
                        {
                            ans[l][m] = '.';
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == '.' || ans[i][j] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << "#";
            }
        }
        cout << endl;
    }
}

int main()
{
    int t = 1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}