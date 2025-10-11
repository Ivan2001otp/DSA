#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void f()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll count = 0, inv = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            ++count;
        else
        {
            inv += count; // counts the inversion
        }
    }

    ans = max(ans, inv);

    // now make the leftmost 0->1.
    vector<ll> b = arr;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            b[i] = 1;
            break;
        }
    }

    count = 0, inv = 0;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            ++count;
        }
        else
        {
            inv += count;
        }
    }

    ans = max(ans, inv);

    // now make the last 1->0
    b = arr;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 1)
        {
            b[i] = 0;
            break;
        }
    }

    count = 0, inv = 0;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            ++count;
        }
        else
        {
            inv += count;
        }
    }

    ans = max(ans, inv);
    cout << ans << endl;
    // cout << "Ans is " << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t;

    while (t--)
    {
        f();
    }

    return 0;
}