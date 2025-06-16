#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    vector<int> prefix(N, 1), suffix(N, 1);

    int c = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 2)
        {
            prefix[i] = ++c;
        }
        else
        {
            prefix[i] = c;
        }
    }

    c = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i] == 2)
            suffix[i] = ++c;
        else
            suffix[i] = c;
    }

    bool flag = false;
    for (int i = 0; i < N - 1; i++)
    {
        if (prefix[i] == suffix[i + 1])
        {
            cout << i + 1 << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}