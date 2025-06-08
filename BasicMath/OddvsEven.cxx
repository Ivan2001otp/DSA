#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;
    ll N;

    while (T--)
    {
        cin >> N;

        if (N % 2 != 0)
        {
            cout << "Odd" << endl;
        }
        else if (N % 4 == 0)
        {
            cout << "Even" << endl;
        }
        else
        {
            cout << "Same" << endl;
        }
    }

    return 0;
}