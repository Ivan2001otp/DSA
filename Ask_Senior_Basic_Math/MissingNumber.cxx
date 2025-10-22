#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;

    vector<ll> v(N);
    ll totalSum = 0;
    ll maxi = INT_MIN;

    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
        maxi = max(maxi, v[i]);
        totalSum += v[i];
    }

    ll n = maxi * (maxi + 1) / 2;
    if (n - totalSum == 0)
    {
        cout << maxi + 1 << endl;
    }
    else
        cout << n - totalSum << endl;
    return 0;
}