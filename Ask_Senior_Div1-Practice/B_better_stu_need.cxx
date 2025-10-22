#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

bool cmp1(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    if (p1.first.first != p2.first.first)
        return p1.first.first > p2.first.first;
    return p1.second < p2.second;
}

bool cmp2(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    if (p1.first.second != p2.first.second)
    {
        return p1.first.second > p2.first.second;
    }

    return p1.second < p2.second;
}

bool cmp3(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    if (p1.first.first + p1.first.second != p2.first.first + p2.first.second)
    {
        return p1.first.first + p1.first.second > p2.first.first + p2.first.second;
    }

    return p1.second < p2.second;
}

bool cmp4(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    return p1.second < p2.second;
}

void solve()
{

    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<pair<pair<int, int>, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first.first;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first.second;
    }

    for (int i = 0; i < N; i++)
    {
        v[i].second = i;
    }
    for (auto a : v)
    {
        cout << a.first.first << "," << a.first.second << " : " << a.second << endl;
    }

    sort(v.begin(), v.end(), cmp1);

    sort(v.begin() + X, v.end(), cmp2);

    sort(v.begin() + X + Y, v.end(), cmp3);

    sort(v.begin(), v.begin() + X + Y + Z, cmp4);
    for (int i = 0; i < X + Y + Z; i++)
    {
        cout << v[i].second + 1 << endl;
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