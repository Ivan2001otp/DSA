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

    int maxi = -1e9, maxi2 = -1e9;

    for (int i = 0; i < N; i++)
    {
        if (v[i] > maxi)
        {
            maxi2 = maxi;
            maxi = v[i];
        }

        if (v[i] > maxi2 && v[i] < maxi)
        {
            maxi2 = v[i];
        }
    }

    if (maxi2 == -1e9)
    {
        maxi2 = maxi;
    }

    for (int i = 0; i < N; i++)
    {
        if (v[i] == maxi)
        {
            v[i] = v[i] - maxi2;
        }
        else
        {
            v[i] = v[i] - maxi;
        }
    }

    for (auto a : v)
        cout << a << " ";
    cout << endl;
    return;
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
