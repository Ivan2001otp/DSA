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
    vector<ll> arr(N);
    vector<ll> even, odd;

    ll ele;
    for (ll i = 0; i < N; i++)
    {
        cin >> ele;

        if (ele & 1)
        {
            odd.push_back(ele);
        }
        else
        {
            even.push_back(ele);
        }
    }

    if (even.size() == 1 && odd.size() == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        ll k = odd.size();
        ll l = even.size();
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        ll ans1 = 0, ans2 = 0;

        if (k - 2 >= 0)
            ans1 = odd[k - 1] + odd[k - 2];
        if (l - 2 >= 0)
            ans2 = even[l - 1] + even[l - 2];

        cout << max(ans1, ans2) << endl;
    }

    return 0;
}