#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    string s;
    cin >> s;

    int diff = abs(('M' - 'a') - ('F' - 'a'));
    bool found = true;

    for (int i = 1; i < N; i++)
    {

        if (abs((s[i] - 'a') - (s[i - 1] - 'a')) != diff)
        {
            found = false;
            break;
        }
    }

    if (!found)
    {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
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