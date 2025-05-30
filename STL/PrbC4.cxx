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
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int ans;
    if (K == 0)
    {
        ans = v[0] - 1;
    }
    else
    {
        ans = v[K - 1];
    }

    int cnt = 0;
    for (auto a : v)
    {
        if (ans >= a)
            cnt++;
    }

    if (ans < 1 || ans > (ll)1e9 || cnt != K)
    {
        cout << -1 << endl;
    }

 else cout << ans << endl;
    return 0;
}