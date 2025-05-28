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

    vector<pair<string, ll>> v(N);

    for (ll i = 0; i < N; i++)
    {
        string s;
        ll salary;
        cin >> s;
        cin >> salary;

        v[i] = {s, salary};
    }

    sort(v.begin(), v.end(), [](pair<string, ll> &a, pair<string, ll> &b)
         {
             if (a.second != b.second)
             {
                 return a.second > b.second;
             }
             return a.first < b.first;
         });


    for (auto a : v)
    {
        cout << a.first << " " << a.second << endl;
    }
}