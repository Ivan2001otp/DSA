#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int K;
    cin >> K;

    vector<int> v;
    for (int i = 1;; i++)
    {
        int lastdigit = i % 10;
        bool isDivisible = (i % 3 == 0);

        if (lastdigit == 3 || isDivisible)
        {
            continue;
        }
        K--;
        if (K == 0)
        {
            cout << i << endl;

            break;
        }
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}