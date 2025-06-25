#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;

    vector<string> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }

    int forCount = 0, againstCount = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == "For")
        {
            forCount++;
        }
        else
        {
            againstCount++;
        }
    }

    if (forCount > againstCount)
    {
        cout << "Yes" << endl;
        return;
    }

    cout << "No" << endl;
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