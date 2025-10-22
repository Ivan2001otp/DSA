#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct PairHash
{

    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

void solve()
{
    int N;
    cin >> N;
    string s;

    cin >> s;

    unordered_map<pair<int, int>, bool, PairHash> mp;
    int x = 0, y = 0;

    bool gotCandy = false;

    mp[{x, y}] = 1;
    for (int i = 0; i < N; i++)
    {

        if (s[i] == 'L')
        {
            x -= 1;
        }
        else if (s[i] == 'R')
        {
            x += 1;
        }
        else if (s[i] == 'U')
        {
            y += 1;
        }
        else
        {
            y -= 1;
        }

        if (x == 1 && y == 1)
        {
            gotCandy = 1;
            cout << "Yes" << endl;
            break;
        }
    }

    if (gotCandy)
        return;
    cout << "No" << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
