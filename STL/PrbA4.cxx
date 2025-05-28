#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    int64_t n;
    cin >> q >> n;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int64_t x;
            cin >> x;
            n = n | x;
        }
        else if (type == 2)
        {
            int64_t x;
            cin >> x;
            n = n & x;
        }
        else if (type == 3)
        {
            int64_t x;
            cin >> x;
            n = n ^ x;
        }
        else if (type == 4)
        {
            n = ~n;
        }

        cout << n << '\n';
    }

    return 0;
}