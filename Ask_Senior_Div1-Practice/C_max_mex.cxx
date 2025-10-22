#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, K;
    cin >> N >> K;
    set<int> v;

    for (int i = 0; i < N; i++)
    {
        int ele;
        cin >> ele;
        v.insert(ele);
    }

    int c = 0;
    for (int i = 0; i < K; i++)
    {
        if (v.count(i) == 0)
        {
            break;
        }
        c++;
    }

    cout << c << endl;
    return;
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