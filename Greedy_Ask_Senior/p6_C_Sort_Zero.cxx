#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// https://codeforces.com/problemset/problem/1712/C
void f()
{
    int n;
    cin >> n;

    vector<ll> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    unordered_map<int, int> mp;

    int break_index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > v[i + 1])
        {
            break_index = i;
            break;
        }
    }

    if (break_index == -1)
    {

        cout << 0 << endl;
        return;
    }

    for (int i = 0; i <= break_index; i++)
    {
        mp[v[i]] = 1;
    }

    // recheck if there is any invalid elements in valid region
    int pos = break_index;
    for (int i = n - 1; i >= break_index; i--)
    {
        if (mp.find(v[i]) != mp.end())
        {
            pos = i;
            break;
        }
    }

    for (int i = break_index; i <= pos; i++)
    {
        mp[v[i]] = 1;
    }

    cout << mp.size() << endl;

    return;
}

int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}