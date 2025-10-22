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

    if (N == 1)
    {
        if (v[0] == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return;
    }
    int mx = 0;

    int sum = 0;
    int cnt = 0;

    int i = 0;
    for (i = 0; i < N; i++)
    {
        if (sum + v[i] == 0)
        {
            cnt++;
        }
        else
        {
            mx = max(cnt, mx);
            cnt = 0;
            sum = 0;
        }
    }

    mx = max(cnt, mx);
    cout << mx << endl;
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
