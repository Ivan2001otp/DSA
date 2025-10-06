#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b;
    ll x, y;
    cin >> a >> b >> x >> y;

    if (b < a)
    {
        if (a % 2 == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            if ((a ^ 1) == b)
            {
                cout << y << endl;
                return;
            }
            cout << -1 << endl;
        }
        return;
    }

    ll cost1 = (b - a) * x;
    ll cost2 = 0;
    while (a != b)
    {

        if (a % 2 == 0)
        {
            a = (a ^ 1);
            cost2 += y;
        }
        else
        {
            a = a + 1;
            cost2 += x;
        }
    }

    cout << min(cost1, cost2) << endl;
}

void solveB()
{
    // check if the polygon in closed or not
    ll px, py, qx, qy;
    ll n;
    cin >> n;
    cin >> px >> py >> qx >> qy;

    ll m = ((px - qx) * (px - qx)) + ((py - qy) * (py - qy));

    ll maxi = 0;
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll u;
        cin >> u;
        maxi = max(maxi, u);
        sum += u;
    }

    ll l;
    if (sum - maxi >= maxi)
        l = 0;
    else
        l = maxi - (sum - maxi);

    if (m <= sum * sum && l * l <= m)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

ll maxPow2(ll n)
{
    ll i = 0;
    while (pow(2, i) <= n)
        i++;

    return --i;
}

void solveC()
{
    ll n, l, r, k;
    cin >> n >> l >> r >> k;

   
    if (n % 2 == 1)
    {
        cout << l << endl;
        return;
    }

    /*
        Let’s say:

            Input:
            l = 6 = 0110
            r = 9

            Now:
            maxpow2(6) gives 2 (because 2^2 = 4 ≤ 6 < 8)
            So x = pow(2, 3) = 8 = 1000

            Then:
            l & x = 0110 & 1000 = 0000 = 0 ✅
            And 8 ∈ [l, r] ⇒ We can use it.
    */
    else 
        if (pow(2, maxPow2(l) + 1) <= r && n != 2)
        {
            if (k <= n - 2)
                cout << l << endl;
            else
                cout << (ll)pow(2, maxPow2(l) + 1) << endl;
        }
        else {cout << -1 << endl;}
}

signed int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solveC();
    }
    return 0;
}