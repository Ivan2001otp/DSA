#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int c = 0;

    vector<int> v;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            c++;

        v.push_back(c);
    }

        int Q;
    cin >> Q;

    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        if (l == 0)
        {
            cout << v[r] << endl;
        }
        else
        {
            cout << v[r] - v[l - 1] << endl;
        }
    }

    return 0;
}