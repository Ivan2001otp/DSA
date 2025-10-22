#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> arr(H, vector<char>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cin >> arr[i][j];
    }

    int cnt = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (arr[i][j] == '#')
                cnt++;
        }
    }
    cout << cnt << endl;
    return;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}