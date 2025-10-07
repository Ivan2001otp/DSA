#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> prefix(N);
    vector<int> suffix(N);

    prefix[0] = v[0];
    for (int i = 1; i < N; i++)
    {
        prefix[i] = max(prefix[i - 1], v[i]);
    }

    suffix[N - 1] = v[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], v[i]);
    }

    for (int i = 0; i < N; i++)
    {
        cout << suffix[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << prefix[i] << " ";
    }
    
    return;
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
