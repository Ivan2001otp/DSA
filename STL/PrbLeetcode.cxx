#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef long long ll;
class Solution
{
public:
    bool isPrime(ll n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (ll i = 5; i * i <= n; i = i + 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s)
    {
        set<ll> unique;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                string sub = s.substr(i, j - i + 1);
                ll num = std::stoll(sub);

                if (isPrime(num))
                {
                    unique.insert(num);
                }
            }
        }

        vector<ll> primes(unique.begin(), unique.end());
        sort(primes.rbegin(), primes.rend());

        ll sum = 0;

        for (ll i = 0; i < min(3, (int)primes.size()); i++)
        {
            sum += primes[i];
        }

        return sum;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "0202";

    int k = 0;
    while (s[k] == '0')
        k++;
    s = s.substr(k);
    // cin >> s;

    set<string> st;
    priority_queue<ll> pq;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string t = s.substr(i, j - i + 1);
            st.insert(t);
        }
    }

    for (auto a : st)
    {
        ll num = stoll(a);
        vector<bool> v = sieve(num);

        if (v[num])
        {
            cout << num << " ";
            pq.push(num);
        }
    }

    if (pq.empty())
    {
        return 0;
    }

    ll sum = 0;
    if (pq.size() >= 3)
    {
        ll e1 = pq.top();
        pq.pop();

        ll e2 = pq.top();
        pq.pop();

        ll e3 = pq.top();
        pq.pop();

        sum = e1 + e2 + e3;
    }
    else
    {
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << "sum is " << sum << endl;
    return 0;
}