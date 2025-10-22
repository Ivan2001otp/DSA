#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    unordered_map<int, int> mp;

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (mp.count(v[i]) == 0)
        {
            ++count;
            mp[v[i]] = 1;
        }
        else
        {

            if (mp.count(-v[i]) == 0)
            {
                ++count;
                mp[-v[i]] = 1;
            }
            else
            {
                continue;
            }
        }
    }

    cout << count << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
