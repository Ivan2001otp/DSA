#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int N, D;
    cin >> N >> D;

    string s;
    cin >> s;

    int index = -1;

    for (int i = 0; i < N; i++)
    {
        if (s[i] - '0' < D)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << s << D << endl;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            cout << s[i];
        }
        if (index != -1)
            cout << D;

        for (int i = index; i < N; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin >> t;
    // vector<ll> prime = sieve(100000);
    while (t--)
    {
        solve();
    }
    return 0;
}