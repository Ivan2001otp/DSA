#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nc2(ll n)
{
    return (n * (n - 1)) / 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;

    vector<ll> v(N);
    unordered_map<ll, ll> mp;

    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
       
    }

    for(auto a : v) {
        mp[a]++;
    }

    ll total = nc2(N);
    ll invalid = 0;

    for (auto a : mp)
    {
        invalid += nc2(a.second);
    }

    cout << total - invalid << endl;

    return 0;
}