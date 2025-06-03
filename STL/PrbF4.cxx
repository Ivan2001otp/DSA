#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    unordered_map<int, int> left, right;
    vector<int> pos(N);
    
    for (int i = 0; i < N; i++)
    {
        if (left.find(v[i]) == left.end())
        {
            left[v[i]] = i;
        }
        right[v[i]] = i;
    }

    for (int i = 0; i < N; i++)
    {
        if (right[v[i]] == i)
        {
            pos[i] = 1;
        }
    }

    // suffix
    for (int i = N - 2; i >= 0; i--)
    {
        pos[i] += pos[i + 1];
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (left[v[i]] == i)
        {
            ans += pos[i];
        }
    }

    cout << "ans : " << ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
