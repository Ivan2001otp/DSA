#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N - 1, 0));
    vector<int> result;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            cin >> v[i][j];
        }
    }

    unordered_map<int, int> mp;
    for (int j = 0; j < N; j++)
    {
        mp[v[j][0]]++;
    }

    int msb = -1;
    int msb2 = 0;
    for (auto a : mp)
    {
        if (a.second > 1)
        {
            msb = a.first;
        }
        else if (a.second == 1)
        {
            msb2 = a.first;
        }
    }

    result.push_back(msb);

    string s = "";
    for (int j = 0; j < N; j++)
    {
        if (v[j][0] == msb2)
        {
            for (int i = 0; i < N - 1; i++)
            {
                result.push_back(v[j][i]);
            }
            break;
        }
    }

    for (auto a : result)
    {

        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}