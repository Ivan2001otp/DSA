#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1780/B
const int mod = 1e9 + 10;
void f()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    vector<int> p;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += (a[i]) % mod;
        p.push_back(sum);
    }

    int ans = -1;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, __gcd(p[i], sum - p[i]));
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}