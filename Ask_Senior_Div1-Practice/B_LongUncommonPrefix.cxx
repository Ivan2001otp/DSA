#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    string S;
    cin >> N >> S;

    int i = 0;
    int cnt = 1;

    vector<int> v;
    int l;
    while (cnt <= N - 1)
    {
        l = 0;
        bool loopHoleFound = false;
        for (int j = 0; j < N - cnt; j++)
        {
            if (S[j] != S[j + cnt])
            {
                l++;
            }
            else
            {
                loopHoleFound = true;
                v.push_back(l);
                break;
            }
        }

        if (!loopHoleFound)
        {
            v.push_back(l);
        }

        cnt++;
    }

    for (auto a : v)
    {
        cout << a << " ";
    }
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