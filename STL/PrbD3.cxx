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
    vector<ll> a(N), b(N);
    a = {4, 8, 2, 6, 2};
    b = {4, 5, 4, 1, 3};

    for (ll i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    vector<ll> diff(N);

    for (ll i = 0; i < N; i++)
    {
        diff[i] = a[i] - b[i];
    }

    sort(diff.begin(), diff.end());
    ll count = 0;

    for (ll i = 0; i < N; i++)
    {

        if (diff[i] <= 0)
        {
            continue;
        }

        auto pos = upper_bound(diff.begin(), diff.end(), -diff[i]) - diff.begin();

        count += abs(pos - i);
    }

    cout << count << endl;
    return 0;
}