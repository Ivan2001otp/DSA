#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, Q;
    cin >> N >> Q;
    unordered_map<int, int> yellow;
    unordered_map<int, int> red;

    int eventType;
    int player;
    while (Q--)
    {
        cin >> eventType >> player;

        if (eventType == 1)
        {
            yellow[player]++;
        }
        else if (eventType == 2)
        {
            red[player] = 1;
        }
        else
        {
            if (red[player])
            {
                cout << "Yes" << endl;
            }
            else if (yellow[player] == 2)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}