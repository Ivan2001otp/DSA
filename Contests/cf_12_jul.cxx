#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, L, R;
    cin >> N >> L >> R;

    vector<pair<int, int>> v(N);
    int from, to;

    for (int i = 0; i < N; i++)
    {
        cin >> from >> to;
        v[i] = {from, to};
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if ((v[i].first <= L))
        {

            if (v[i].second >= R)
            {
                ++count;
            }
        }
    }

    cout << count << endl;
}

void solve2()
{
    ll N;
    cin >> N;
    vector<pair<char, ll>> v(N);

    char ch;
    ll l;
    for (ll i = 0; i < N; i++)
    {
        cin >> ch >> l;
        v[i] = {ch, l};
    }

    bool isLong = false;
    ll res = 0;
    string s = "";

    for (int i = 0; i < N; i++)
    {
        if (i + 1 < N)
            if (v[i].first == v[i + 1].first)
                continue;

        if (v[i].second > 100)
        {
            isLong = true;
            break;
        }
        else
        {
            res += v[i].second;

            for (int j = 1; j <= v[i].second; j++)
            {
                s.push_back(v[i].first);
            }
        }

        if (res > 100)
        {
            isLong = true;
            break;
        }
    }

    if (isLong)
    {
        cout << "Too long" << endl;
        return;
    }

    cout << s;
}

bool isPalindrome(const string &s)
{
    return s == string(s.rbegin(), s.rend());
}

string toBase(ll x, int A)
{
    string res;

    while (x > 0)
    {
        res = res + char((x % A) + '0');
        x = x / A;
    }

    reverse(res.begin(), res.end());
    return res;
}

void solve3()
{
    ll A, N;
    cin >> A >> N;
    ll sum = 0;

    for (int half = 1;; ++half)
    {
        string s = to_string(half);
        string rev = s;
        reverse(rev.begin(), rev.end());

        // Odd-length palindrome
        string oddStr = s + rev.substr(1);
        ll oddVal = stoll(oddStr);
        if (oddVal > N)
            break;
        if (isPalindrome(toBase(oddVal, A)))
            sum += oddVal;

        // Even-length palindrome
        string evenStr = s + rev;
        ll evenVal = stoll(evenStr);
        if (evenVal <= N && isPalindrome(toBase(evenVal, A)))
            sum += evenVal;
    }

    cout << sum << endl;
    return;
}

signed int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve3();
    }
    return 0;
}