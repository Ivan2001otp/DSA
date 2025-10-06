#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    sort(s.rbegin(), s.rend());
    cout << s << endl;
}

int gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;

    if (a > b)
    {
        return gcd(a - b, b);
    }

    return gcd(a, b - a);
}
void solveB()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll g = __gcd(a, b);

    cout << (max(a / g, b / g) <= k ? 1 : 2) << endl;
}

// 2,3,5,7
//  gives the numbers that are divisible by 2,3,5,7... also counts the bigger numbers
//  that are formed by 2,3,5,7.
long long ask(long long x)
{
    return x - (x / 2) - (x / 3) - (x / 5) - (x / 7) + (x / 6) + (x / 10) + (x / 14) + (x / 15) + (x / 21) + (x / 35) - (x / 105) - (x / 70) - (x / 42) - (x / 30) + (x / 210);
}

void solveC()
{
    ll l, r;
    cin >> l >> r;
    // total - not_good
    // we find not_good from inclusion-exclusion principle
    cout << ask(r) - ask(l - 1) << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solveC();
    return 0;
}