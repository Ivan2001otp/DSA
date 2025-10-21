#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1706/B
void f()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int currSum = 0;
    int start = 0;
    int ans = 0;

    while (start < s.size() && s[start] == '1')
    {
        ans += v[start];
        ++start;
    }

    int last = 0;
    int mini = INT_MAX;
    for (int i = start; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (last == 1)
            {
                ans += (currSum - mini);
            }

            last = 0;
            currSum = v[i];
            mini = v[i];
        }
        else
        {
            currSum += v[i];
            mini = min(mini, v[i]);
            last = 1;
        }
    }

    if (last)
    {
        ans += (currSum - mini);
    }

    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}