#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int H, W;
    cin >> H >> W;

    vector<vector<int>> v(H, vector<int>(W));

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> v[i][j];
        }
    }

    char ch = 'A';
    unordered_map<int, char> mp;

    mp[0] = '.';
    for (int i = 1; i <= 26; i++)
    {
        mp[i] = ch++;
    }

        for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << mp[v[i][j]];
        }
        cout << endl;
    }
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}