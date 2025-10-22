#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    int X;
    cin >> X;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N; i++)
    {
        if (v[i] == X)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}