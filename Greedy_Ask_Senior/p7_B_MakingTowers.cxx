#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1706/B 
void f()
{
    int n;
    cin >> n;
    vector<int> v(n);

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]].push_back(i);
    }

    vector<int> ans(n, 0);
    for (auto mapele : mp)
    {
        vector<int> diff = mapele.second;
        int size = 1;

        for (int i = 0; i < diff.size() - 1; i++)
        {

            if ((diff[i + 1] - diff[i]) % 2 == 1)
            {
                ++size;
            }
        }
        ans[mapele.first - 1] = size;
    }

    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
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