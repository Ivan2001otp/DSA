#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int dx[] = {-1, 1, 0, -1, 0, 1, 1, -1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};

void solve()
{
    int R;
    int C;
    cin >> R >> C;
    vector<string> A(R);
    vector<string> B(R);

    for (int i = 0; i < R; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < R; i++)
    {
        cin >> B[i];
    }

    for (int s = 0; s < R; s++)
    {
        for (int t = 0; t < C; t++)
        {
            bool flag = true;
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (A[i][j] != B[(i + s) % R][(j + t) % C])
                    {
                        flag = false;
                        break;
                    }
                }

                if (!flag)
                {
                    break;
                }
            }

            if (flag)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
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