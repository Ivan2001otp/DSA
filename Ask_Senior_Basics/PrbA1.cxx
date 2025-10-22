#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S, T;
    bool flag = false;

    cin >> S;
    cin >> T;
    int len = min(S.size(), T.size());
    for (int i = 0; i < len; i++)
    {
        if (S[i] == T[i])
        {
            continue;
        }
        else
        {
            if (S[i] < T[i])
            {
                cout << S << endl;
            }
            else
            {
                cout << T << endl;
            }

            flag = true;
            break; 
        }

    }

    if (!flag)
    {
        if (S.size() > T.size())
        {
            cout << T << endl;
        }
        else
        {
            cout << S << endl;
        }
    }

    return 0;
}