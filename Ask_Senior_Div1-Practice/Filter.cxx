#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (auto a : v)
    {
        if (a % 2 == 0)
        {
            cout << a << " ";
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}