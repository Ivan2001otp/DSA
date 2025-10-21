#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1729/D
void f()
{
    int n;
    cin >> n;

    vector<int> diff(n);
    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < n; i++)
        cin >> v2[i];

    multiset<int> mt;
    vector<int> trash;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        diff[i] = v2[i] - v1[i];
        if (diff[i] >= 0)
        {
            mt.insert(diff[i]);
        }
        else
        {
            trash.push_back(diff[i]);
        }
    }

    for (auto it : trash)
    {
        auto itr = mt.lower_bound(abs(it));
        if (itr != mt.end())
        {
            ++cnt;
            mt.erase(itr);
        }
    }

    cnt += mt.size() / 2;

    cout << "ans : " << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}