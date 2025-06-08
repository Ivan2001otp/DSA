#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, K;

    cin >> N >> K;

    vector<pair<ll, ll>> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    vector<ll> ans(N, K / N);

    int left = K - (K / N) * N;
    for (int i = 0; i < left; i++)
    {
        ans[v[i].second]++;
    }

    for (auto a : ans)
    {
        cout << a << endl;
    }

    return 0;
}