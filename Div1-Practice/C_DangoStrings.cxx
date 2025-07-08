#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    string S;
    cin >> N >> S;

    int maxi = 0;
    int count = 0;
    bool found = 0;

    count = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'o')
        {
            count++;
        }
        else
        {

            found = 1;
            maxi = max(maxi, count);
            count = 0;
        }
    }

    maxi = max(maxi, count);

    if (maxi > 0 && found)
    {
        cout << maxi << endl;
        return;
    }

    cout << -1 << endl;
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