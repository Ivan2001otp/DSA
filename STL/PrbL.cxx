#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    unordered_map<int, int> mp;

    bool teamFormed = false;

    for (int i = 0; i < N; i++)
    {
        
        if (mp.size() == K)
        {
            teamFormed = true;
            break;
        }

        if (mp.count(v[i]) == 0)
        {
            mp[v[i]] = i;
        }
    }

    if (mp.size() == K) teamFormed = true;
  
    if (!teamFormed)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;

        for (auto a : mp)
        {
            cout << a.second + 1 << " ";
        }
    }
}