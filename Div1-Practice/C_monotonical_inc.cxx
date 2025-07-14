#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> dp[10][10];

void f(int N, int M)
{
    if (dp[N][M].size())
        return;

    if (N == 1)
    {
        for (int i = 1; i <= M; i++)
        {
            dp[N][M].push_back({i});
        }
    }
    else
    {
        for (int k = 1; k <= M; k++)
        {
            if (N - 1 <= k - 1)
            {
                f(N - 1, k - 1);

                // backtrack
                for (int i = 0; i < dp[N - 1][k - 1].size(); i++)
                {
                    vector<int> a = dp[N - 1][k - 1][i];
                    a.push_back(k); // add last element.
                    dp[N][M].push_back(a);
                }
            }
        }
    }
}

void solve()
{
    int N, M;
    cin >> N >> M;

    f(N, M);
    sort(dp[N][M].begin(), dp[N][M].end());
    for (int i = 0; i < dp[N][M].size(); i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << dp[N][M][i][j] << " ";
        }
        cout << endl;
    }
}

void f1(int open, int close, vector<string> &res, string s)
{

    if (open == 0 && close == 0)
    {
        res.push_back(s);
        return;
    }

    if (open > 0)
    {
        f1(open - 1, close, res, s + "(");
    }

    if (close > open)
    {
        f1(open, close - 1, res, s + ")");
    }
}
// valid parenthesis.
void solve2()
{
    int n = 3;

    vector<string> res;
    f1(n, n, res, "");

    for (auto a : res)
    {
        cout << a << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}