#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> p(M);
    for (int i = 0; i < M; i++)
    {
        int C;
        cin >> C;
        p[i].resize(C);
        for (int j = 0; j < C; j++)
        {
            int a;
            cin >> a;
            p[i][j] = a;
        }
    }

    // we have to mask 1...N numbers to how many sets has all values from 1...N.
    int full_mask = (1 << N) - 1;
    int c = 0;

    // logic to check 1...N values  are present in how many sets
    for (int bit = 1; bit < (1 << M); bit++)
    {
        int union_mask = 0;
        for (int i = 0; i < M; i++)
        {
            if (bit & (1 << i))
            {
                // converting set elements to bit mask
                for (auto a : p[i])
                    union_mask |= (1 << (a - 1));
            }
        }

        if (union_mask == full_mask)
        {
            c++;
        }
    }

    cout << c << endl;
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