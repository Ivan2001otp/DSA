#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int mat[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> mat[i][j];
        }
    }

    bool res1 = (mat[0][0] > mat[0][1]);
    bool res2 = (mat[1][0] > mat[1][1]);

    bool res3 = (mat[0][1] > mat[0][0]);
    bool res4 = (mat[1][1] > mat[1][0]);

    if (res1 && res2)
    {
        bool res5 = (mat[0][0] > mat[1][0]);
        bool res6 = (mat[0][1] > mat[1][1]);

        bool res7 = (mat[0][0] < mat[1][0]);
        bool res8 = (mat[0][1] < mat[1][1]);

        if (res5 && res6)
        {
            cout << "Yes" << endl;
            return;
        }
        else if (res7 && res8)
        {
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
        return;
    }

    else if (res3 && res4)
    {
        bool res5 = (mat[0][0] > mat[1][0]);
        bool res6 = (mat[0][1] > mat[1][1]);

        bool res7 = (mat[0][0] < mat[1][0]);
        bool res8 = (mat[0][1] < mat[1][1]);

        if (res5 && res6)
        {
            cout << "Yes" << endl;
            return;
        }
        else if (res7 && res8)
        {
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
        return;
    }

    cout << "No" << endl;
}

signed int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}