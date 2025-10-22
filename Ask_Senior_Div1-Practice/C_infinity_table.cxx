#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int k;
    cin >> k;

    int c = 1;
    bool found = false;
    int st = 0;
    int end = 0;
    while (!found)
    {

        st = end + 1;
        end = st + (c - 1) + (c - 1);
        // cout << "value of c : " << c << endl;
        // cout << "start:" << st << ", end:" << end << endl;
        // cout << endl;

        if (st == k)
        {
            cout << 1 << " " << c << endl;
            found = true;
            break;
        }
        else if (end == k)
        {
            cout << c << " " << 1 << endl;
            found = true;
            break;
        }
        else if (st < k && k < end)
        {

            int stPtr = st;

            int med = st + c - 1;
            if (st < k && k <= med)
            {
                int rem = k - st;
                cout << rem + 1 << " " << c << endl;
                found = true;
            }
            else
            {

                int rem = k - med;
                cout << c << " " << (c - rem) << endl;
                found = true;
            }
            break;
        }

        c++;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}