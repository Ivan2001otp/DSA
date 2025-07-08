#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_ok(char ch)
{
    static const string str = "atcoder";
    return str.find(ch) != string::npos;
}

void solve()
{

    vector<int> cntT(26, 0);
    vector<int> cntS(26, 0);
    int atS = 0, atT = 0;

    string S, T;
    cin >> S >> T;

    for (auto a : S)
    {
        if (a == '@')
        {
            atS++;
        }
        else
        {
            cntS[a - 'a']++;
        }
    }

    for (auto a : T)
    {
        if (a == '@')
        {
            atT++;
        }
        else
        {
            cntT[a - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        char ch = 'a' + i;

        if (!is_ok(ch))
        {

            if (cntT[i] != cntS[i])
            {
                cout << "No" << endl;
                return;
            }
        }
        else
        {

            if (cntT[i] < cntS[i])
            {
                atT = atT - (cntS[i] - cntT[i]);
            }
            else if (cntT[i] > cntS[i])
            {
                atS -= (cntT[i] - cntS[i]);
            }

            if (atT < 0 || atS < 0)
            {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
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