#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    if (N == 1 || N == 3)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> v(N);

    if (N % 2)
    {
        int i = N;

        int j = 0;
        while (i > (N / 2 + 1))
        {
            v[j] = i;
            j++;
            --i;
        }

        int p = 1;
        while (j < N)
        {
            v[j] = p;
            j++;
            p++;
        }
    }
    else
    {
        int p = N;
        for (int i = 0; i < N; i++)
        {
            v[i] = p;
            --p;
        }
    }

    for (auto a : v)
        cout << a << " ";
    cout << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
