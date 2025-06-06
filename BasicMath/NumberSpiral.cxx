#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll Q;
    cin >> Q;
    ll r, c;

    while (Q--)
    {
        cin >> r >> c;

        ll diagonal = max(r, c);
        ll diagonal_element = diagonal * diagonal - diagonal + 1; // n2 - n +1
        if (diagonal & 1)
        {
            if (diagonal == r)
            {
                // along column
                ll diff = abs(c - diagonal);
                cout << diagonal_element - diff << endl;
            }
            else
            {
                // along row
                ll diff = abs(r - diagonal);
                cout << diagonal_element + diff << endl;
            }
        }
        else
        {
            if (diagonal == r)
            {
                // along column
                ll diff = abs(c - diagonal);
                cout << diagonal_element + diff << endl;
            }
            else
            {
                // along row
                ll diff = abs(r - diagonal);
                cout << diagonal_element - diff << endl;
            }
        }
    }
    return 0;
}