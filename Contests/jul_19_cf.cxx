#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve()
{
    int x;
    cin >> x;
    int last;
    int mini = 1e9;
    while (x != 0)
    {
        last = x % 10;
        x = x / 10;
        mini = min(last, mini);
    }

    cout << mini << endl;
}

void solveB()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n + 1);

    for (ll j = 0; j < n; j++)
    {
        cin >> arr[j];
    }

    ll count = 0;

    ll c = 0;

    ll i = 0;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            ++c;

            if (c == k)
            {
                ++count;

                i = i + 2;
                c = 0;
            }
            else
            {
                ++i;
            }
        }
        else
        {

            c = 0;
            ++i;
        }
    }

    cout << count << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solveB();
    return 0;
}