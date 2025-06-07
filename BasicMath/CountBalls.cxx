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
    ll A, B;
    cin >> A >> B;

    ll ans = 0;
    ll x = N / (A + B);

    ll rem = N % (A + B);
    ll c2 = 0;

    if (rem != 0)
    {
        c2 = min(A, rem);
    }

    ans = x * A + c2;
    cout << ans << endl;

    return 0;
}