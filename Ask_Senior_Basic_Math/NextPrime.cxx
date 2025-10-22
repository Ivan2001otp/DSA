#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll X;
    cin >> X;
    ll N = 1e5 + 10;
    vector<bool> prime(N, true);

    for (ll p = 2; p * p <= N; p++)
    {

        if (prime[p] == true)
        {

            for (ll i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (ll p = 2; p <= N; p++)
        if (prime[p])
        {
            if (p > X)
            {
                cout << p << endl;
                break;
            }
        }

    return 0;
}