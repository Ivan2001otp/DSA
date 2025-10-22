#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](const int &a, const int &b)
         { return a % 2 < b % 2; });

    int total = 0;
    int m = 0;
    for (int i = 0; i < N; i++)
    {
        total += v[i];

        if (v[i] % 2 == 0)
        {
            m += v[i];
        }
    }

    if (m > (total - m))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
